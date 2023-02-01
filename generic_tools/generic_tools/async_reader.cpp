#include "async_reader.h"
namespace generic_tools {


	async_reader::async_reader() {}


	async_reader::async_reader(std::vector<std::string>* paths)
	{
		this->_user_paths_ptr = paths;
	}

	

	void async_reader::SetFiles(std::vector<std::string> * paths)
	{

		if (this->_user_paths_ptr != nullptr)
			delete _user_paths_ptr;

		this->_user_paths_ptr = paths;
	}

	std::unordered_map<std::string*, std::string*>* async_reader::GetResult()
	{
		return &_success;
	}

	int async_reader::ReadFilesAsync(std::vector<std::string>* paths)
	{
		this->SetFiles(paths);

		return ReadFilesAsync();
		
	}

	int async_reader::ReadFilesAsync()
	{
		if (_user_paths_ptr == nullptr) return _PASSED_NULLPTR;
		if (_user_paths_ptr->empty()) return _PASSED_EMPTY_PATHS;

		for (int i = 0; i < _user_paths_ptr->size(); ++i) {

			std::string* current_file = &_user_paths_ptr->at(i);
			
			std::future<int> result = std::async(&async_reader::ReadFileAsyncInternal,this, current_file);
						

			std::pair<std::string*, int> status_pair(current_file,result.get());
			
			_statuses.insert(status_pair);
			

		}

		return _FINISHED;

	}

	int async_reader::GetStatus()
	{
		if (!_failed.empty() && !_success.empty())
			return _PARTIALY_READ;

		if (_failed.empty() && !_success.empty()) {
			if (_user_paths_ptr->size() == _success_count) {
				return _READ_ALL;
			}
		}

		return _FAILED_ALL;
	}

	std::vector<std::string*>* async_reader::GetFailedToRead()
	{
		return &_failed;
	}

	int async_reader::ReadFileAsyncInternal(std::string* path) {
		
		std::ifstream file(*path);
			

		if (!file.is_open()) {
			

			_failed_mutex.lock();
			_failed.push_back(path);
			_failed_mutex.unlock();

			return _SINGLE_FILE_FAIL;

		}

		std::string file_content;
		std::ostringstream file_content_buff;



		

		file_content_buff << file.rdbuf();

		file_content = file_content_buff.str();

		std::pair<std::string*, std::string*> pair(path,&file_content);

		_success_mutex.lock();

		_success.insert(pair);

		_success_mutex.unlock();

		_success_count++;

		return _SINGLE_FILE_SUCCESS;

	}
	
	

	async_reader::~async_reader(){}

}
