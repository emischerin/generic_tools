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

	
	class async_reader
	{
		
			

	public:
		

		enum ReadResult {
			_READ_ALL = 0,
			_FAILED_ALL = 1,
			_PARTIALY_READ = 2,
			_PASSED_EMPTY_PATHS = 3,
			_PASSED_NULLPTR = 4,
			_FINISHED = 5,
			_SINGLE_FILE_SUCCESS = 6,
			_SINGLE_FILE_FAIL = 7

		};

		


		async_reader();

		async_reader(std::vector<std::string>* paths);

		


		void SetFiles(std::vector<std::string>* paths);

		std::unordered_map<std::string*, std::string>* GetResult();

		int ReadFilesAsync(std::vector<std::string>* paths);

		int ReadFilesAsync();

		int GetStatus();

		std::vector<std::string*>* GetFailedToRead();


		~async_reader();
		

	private:
		
		
		int ReadFileAsyncInternal(std::string* path);
		std::vector<std::string*> _failed;
		
		std::unordered_map<std::string*, int> _statuses;
		std::unordered_map<std::string*,std::string> _success;
		std::mutex _failed_mutex;
		
		std::mutex _success_mutex;
		std::atomic<size_t> _success_count;
		std::vector<std::string>* _user_paths_ptr = nullptr;


		

	};
}

