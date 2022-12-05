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
		using files_statuses = std::unordered_map<std::string*, int>;
		using files_map = std::unordered_map<std::string*, std::string>;
		using paths_ptr_vector = std::vector<std::string*>;
		using paths_vector = std::vector<std::string>;

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

		async_reader(paths_vector* paths);

		


		void SetFiles(paths_vector* paths);

		files_map* GetResult();

		int ReadFilesAsync(paths_vector* paths);

		int ReadFilesAsync();

		int GetStatus();

		paths_ptr_vector* GetFailedToRead();


		~async_reader();
		

	private:
		
		
		int ReadFileAsyncInternal(std::string* path);
		paths_ptr_vector _failed;
		
		files_statuses _statuses;
		files_map _success;
		std::mutex _failed_mutex;
		
		std::mutex _success_mutex;
		std::atomic<size_t> _success_count;
		paths_vector* _user_paths_ptr = nullptr;


		

	};
}

