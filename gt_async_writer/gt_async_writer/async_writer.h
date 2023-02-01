#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <future>
#include <thread>
#include <fstream>
#include <unordered_map>
#include <unordered_set>

namespace generic_tools {


	class async_writer
	{
		
		
		
		
		

	public:


		enum ReadResult {
			_WRITE_ALL = 0,
			_FAILED_ALL = 1,
			_PARTIALY_WRITE = 2,
			_PASSED_EMPTY_PATHS = 3,
			_PASSED_NULLPTR = 4,
			_FINISHED = 5,
			_SINGLE_FILE_SUCCESS = 6,
			_SINGLE_FILE_FAIL = 7,
			_PASSED_EMPTY_CONTENT = 8,
			_FILES_CONTENT_MISSMATCH = 9

		};




		async_writer();

		async_writer(std::vector<std::string*>* paths, std::vector<std::string*>* contents);

		void SetFiles(std::vector<std::string*>* paths, std::vector<std::string*>* contents);

		std::vector<std::string*> * GetResult();

		int WriteFilesAsync(std::vector<std::string*>* paths, std::vector<std::string*>* contents);

		int WriteFilesAsync();

		int GetStatus();

		std::vector<std::string*>* GetFailedToWrite();


		~async_writer();

	private:
		int WriteFileAsyncInternal(std::string* path,std::string* data);
		std::vector<std::string*> _failed;

		std::unordered_map<std::string*, int> _statuses;
		std::vector<std::string*> _success;
		std::mutex _failed_mutex;

		std::mutex _success_mutex;
		std::atomic<size_t> _success_count;
		std::vector<std::string*>* _user_paths_ptr = nullptr;
		std::vector<std::string*>* _files_content = nullptr;
	};
}

