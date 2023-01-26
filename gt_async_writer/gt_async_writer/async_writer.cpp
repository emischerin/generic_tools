#include "async_writer.h"
namespace generic_tools {


	async_writer::async_writer(){}

	async_writer::async_writer(paths_vector* paths, contents_vector* contents)
	{
		this->_user_paths_ptr = paths;;
		this->_files_content = contents;
	}

	void async_writer::SetFiles(paths_vector* paths, contents_vector* contents)
	{

		if (this->_user_paths_ptr != nullptr)
			delete _user_paths_ptr;

		if (this->_files_content != nullptr)
			delete _files_content;

		this->_user_paths_ptr = paths;
		this->_files_content = contents;
	}

	std::vector<std::string*>* async_writer::GetResult()
	{
		return &_success;
	}

	int async_writer::WriteFilesAsync(paths_vector* paths,contents_vector* contents)
	{
		this->SetFiles(paths,contents);

		return WriteFilesAsync();

	}

	int async_writer::WriteFilesAsync()
	{
		if (_user_paths_ptr == nullptr) return _PASSED_NULLPTR;
		if (_user_paths_ptr->empty()) return _PASSED_EMPTY_PATHS;
		if (_files_content == nullptr) return _PASSED_NULLPTR;
		if (_files_content->empty()) return _PASSED_EMPTY_CONTENT;
		if (_files_content->size() != _user_paths_ptr->size()) return _FILES_CONTENT_MISSMATCH;

		for (int i = 0; i < _user_paths_ptr->size(); ++i) {

			std::string* current_file = _user_paths_ptr->at(i);
			std::string* current_data = _files_content->at(i);
			std::future<int> result = std::async(&async_writer::WriteFileAsyncInternal, this, current_file,current_data);


			std::pair<std::string*, int> status_pair(current_file, result.get());

			_statuses.insert(status_pair);


		}

		return _FINISHED;

	}

	int async_writer::GetStatus()
	{
		if (!_failed.empty() && !_success.empty())
			return _PARTIALY_WRITE;

		if (_failed.empty() && !_success.empty()) {
			if (_user_paths_ptr->size() == _success_count) {
				return _WRITE_ALL;
			}
		}

		return _FAILED_ALL;
	}

	std::vector<std::string*>* async_writer::GetFailedToWrite()
	{
		return &_failed;
	}

	int async_writer::WriteFileAsyncInternal(std::string* path,std::string* data) {

		std::ofstream file(*path);


		if (!file.is_open()) {


			_failed_mutex.lock();
			_failed.push_back(path);
			_failed_mutex.unlock();

			return _SINGLE_FILE_FAIL;

		}

	
		file << *data;
			

		_success_mutex.lock();

		_success.push_back(path);

		_success_mutex.unlock();

		_success_count++;

		return _SINGLE_FILE_SUCCESS;

	}

	async_writer::~async_writer(){}
	
};
