#pragma once
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace generic_tools
{
	enum StringProcResult {
		SUCCESS,
		EMPTY_STRING,
		TOKEN_MISSING
	};

	template<class my_char>
	class string_stat {
	public:
		
		string_stat() {};
		string_stat(std::basic_string<my_char>* s) : _data(s){}
		~string_stat(){}

		StringProcResult ProcessString() {
			
			if (!_data) return EMPTY_STRING;
			if (_data->empty()) return EMPTY_STRING;
			if (_this_was_used) ResetDataStructures();

			for (size_t i = 0; i < _data->length(); ++i) {
				my_char tmp = _data->at(i);

				_symbols_count[tmp]++;

				_symbols_positions[tmp].push_back(i);

				_str_length++;
							

			}

			_lines_count = _symbols_positions[_newline].size() + 1;

			_this_was_used = true;

			return SUCCESS;
			
		}

		StringProcResult ProcessString(std::basic_string<my_char>* s) {
			_data = s;
			return this->ProcessString();

		}

		void GetLinesOffsets(std::vector<size_t>& v) {
			
			if(_data)
				if (!_data->empty()) 
					v = _symbols_positions[_newline];
		}

		void GetLinesOffsets(std::vector<size_t>& v,std::basic_string<my_char>& str) {
			if (str->empty()) return;

			int proc_result = this->ProcessString(str);

			if (proc_result != generic_tools::StringProcResult::SUCCESS) {
				return;
			}
			else if(proc_result == generic_tools::StringProcResult::SUCCESS) {
				this->GetLinesOffsets(v);
			}

		}

		std::basic_string<my_char>* GetLine(size_t line_index) {
			
			std::basic_string<my_char>* line;

			//if (line_index == 0) return nullptr;
			if (line_index >= _lines_count) return nullptr;
			if (!_data) return nullptr;
			if (!_this_was_used) return  nullptr;
			if (_lines_count == 1) return _data;

			std::vector<size_t> lines = _symbols_positions[_newline];

			size_t line_pos; 
			
			if (line_index == 0)
				line_pos = lines[0];
			else {
				line_pos = lines[line_index - 1];
			}
			
			if (line_index == 0) {
				line = new std::basic_string<my_char>(*_data, 0, line_pos);
			}
			else if((line_index + 1) == _lines_count){
				line_pos++;
				line = new std::basic_string<my_char>(*_data, line_pos, _str_length - 1);
			}
			else {
				line_pos++;
				size_t next_line_pos = lines[line_index];
				size_t to_copy = (next_line_pos - line_pos);
				line = new std::basic_string<my_char>(*_data, line_pos, to_copy);
			}
			
			return line;
					

		}
		
		std::basic_string<my_char>* GetNextLine(size_t line_index) {
			return this->GetLine(line_index + 1);
		}


		std::vector<std::basic_string<my_char>*>* GetAllLines() {
			
			std::vector<std::basic_string<my_char>*>* result = new std::vector<std::basic_string<my_char>*>();

			if (!_data) return result;
			if (!_this_was_used) return  result;
			if (_lines_count == 1) {
				result->push_back(_data);
				return result;
			}

			for (size_t i = 0; i < _lines_count; ++i) {
				std::basic_string<my_char>* tmp = this->GetLine(i);
				result->push_back(tmp);
			}
			return result;
		}
		
		bool StringMatcher(std::basic_string<my_char>* string,
			std::basic_string<my_char>* pattern) {

			if (!string) return false;
			if (!pattern) return false;
			if (pattern->length() > string->length()) return false;
			if (string->length() == 0) return false;
			if (pattern->length() == 0) return false;

			size_t find = string->find(*pattern);

			return (find != std::basic_string<my_char>::npos);



		}

		std::vector<size_t>* FindStringsContain(std::vector<std::basic_string<my_char>*>* v,
			std::basic_string<my_char>* pattern) {

			if (!pattern) return nullptr;
			if (!v) return nullptr;
			if (pattern->length() == 0) return nullptr;

			std::vector<size_t>* result = new std::vector<size_t>();

			for (size_t i = 0; i < v->size(); ++i) {
				std::basic_string<my_char>* tmp = v->at(i);
				size_t find = tmp->find(*pattern);
				if (find != std::basic_string<my_char>::npos)
					result->push_back(i);
			}
			return result;
		}
		std::vector<size_t>* FindStringsContain(std::vector<std::basic_string<my_char>*>* v,
			std::basic_string<my_char>&& pattern) {

			
			if (!v) return nullptr;
			
			std::basic_string<my_char>& p = pattern;

			std::vector<size_t>* result = new std::vector<size_t>();

			for (size_t i = 0; i < v->size(); ++i) {
				std::basic_string<my_char>* tmp = v->at(i);
				size_t find = tmp->find(p);
				if (find != std::basic_string<my_char>::npos)
					result->push_back(i);
			}
			return result;
		}

		std::vector<std::basic_string<my_char>*>* GetStringsContain(std::vector<std::basic_string<my_char>*>* v,
			std::basic_string<my_char>* pattern) {

			if (!pattern) return nullptr;
			if (!v) return nullptr;
			if (pattern->length() == 0) return nullptr;

			std::vector<std::basic_string<my_char>*>* result = new std::vector<std::basic_string<my_char>*>();

			for (size_t i = 0; i < v->size(); ++i) {
				std::basic_string<my_char>* tmp = v->at(i);
				size_t find = tmp->find(*pattern);
				if (find != std::basic_string<my_char>::npos)
					result->push_back(tmp);
			}
			return result;
		}

		std::vector<std::basic_string<my_char>*>* GetStringsContain(std::vector<std::basic_string<my_char>*>* v,
			std::basic_string<my_char>&& pattern) {

			
			if (!v) return nullptr;
			
			std::basic_string<my_char>& p = pattern;

			std::vector<std::basic_string<my_char>*>* result = new std::vector<std::basic_string<my_char>*>();

			for (size_t i = 0; i < v->size(); ++i) {
				std::basic_string<my_char>* tmp = v->at(i);
				size_t find = tmp->find(p);
				if (find != std::basic_string<my_char>::npos)
					result->push_back(tmp);
			}
			return result;
		}

		std::basic_string<my_char>* ConcatStrings(std::vector<std::basic_string<my_char>*>* str_v) {
			
			if (!str_v) return nullptr;
			if (str_v->size() == 0) return nullptr;
			
			std::basic_string<my_char>* result = new std::basic_string<my_char>();

			for (int i = 0; i < str_v->size(); ++i) {
				if (str_v->at(i)) {
					(*result) += *(str_v->at(i));
				}
			}
			return result;
		}

		void EraseSequence(std::basic_string<my_char>* str,my_char c = _space) {
			
			if(!str) return;
			if (str->empty()) return;
			if (str->size() <= 1) return;
						
			std::unordered_set<size_t> not_copy;

			for (size_t i = 1; i < str->size(); ++i) {
				my_char current = str->at(i);
				my_char prev = str->at(i - 1);

				if (prev == current) {
					
					not_copy.insert(i);
				}
			}

			std::basic_string<my_char> new_str;
			
			StrSkipCopy(str, &new_str, &not_copy);

			*str = new_str;

			
		}

		

		std::basic_string<my_char>* EraseSequenceNewStr(std::basic_string<my_char>* str, my_char c = _space) {

			if (!str) return nullptr;
			if (str->empty()) return nullptr;
			if (str->size() <= 1) return nullptr;
						

			std::unordered_set<size_t> not_copy;

			for (size_t i = 1; i < str->size(); ++i) {
				my_char current = str->at(i);
				my_char prev = str->at(i - 1);

				if (prev == current) {

					not_copy.insert(i);
				}
			}

			std::basic_string<my_char>* new_str = new std::basic_string<my_char>();

			StrSkipCopy(str, new_str, &not_copy);

			return new_str;



		}

	private:

		
		size_t _str_length = 0;
		size_t _lines_count = 0;
		std::basic_string<my_char>* _data = nullptr;
		std::unordered_map<my_char, size_t> _symbols_count;
		std::unordered_map<my_char, std::vector<size_t>> _symbols_positions;
		

		const my_char _space = ' ';
		const my_char _newline = '\n';
		bool _this_was_used = false;

		void ResetDataStructures() {
			_symbols_count.clear();
			_symbols_positions.clear();
			_str_length = 0;
			/* Lines count is always begins at 1 (there is always at least one line at string)
			*  
			*/
			_lines_count = 1;
		}

		
		void StrSkipCopy(std::basic_string<my_char>* str1, std::basic_string<my_char>* str2,
			std::unordered_set<size_t>* not_copy) {

			if (!str1) return;
			if (!str2) return;
			if (!not_copy) return;

			for (size_t i = 0; i < str1->size(); ++i) {
				auto f = not_copy->find(i);
				if (f == not_copy->end()) {
					str2->push_back(str1->at(i));
				}

			}

		}

	};
}
