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
		using files_statuses = std::unordered_map<std::string*, int>;
		using files_map = std::vector<std::string*>;
		using paths_ptr_vector = std::vector<std::string*>;
		using paths_vector = std::vector<std::string*>;
		using contents_vector = std::vector<std::string*>;

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

		async_writer(paths_vector* paths,contents_vector* contents);

		void SetFiles(paths_vector* paths,contents_vector* contents);

		files_map* GetResult();

		int WriteFilesAsync(paths_vector* paths, contents_vector* contents);

		int WriteFilesAsync();

		int GetStatus();

		paths_ptr_vector* GetFailedToWrite();


		~async_writer();

	private:
		int WriteFileAsyncInternal(std::string* path,std::string* data);
		paths_ptr_vector _failed;

		files_statuses _statuses;
		files_map _success;
		std::mutex _failed_mutex;

		std::mutex _success_mutex;
		std::atomic<size_t> _success_count;
		paths_vector* _user_paths_ptr = nullptr;
		contents_vector* _files_content = nullptr;
	};
}

