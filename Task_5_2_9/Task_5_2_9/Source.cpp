#include <cstddef> // size_t

struct String {
	String(const char *str = "");
	String(size_t n, char c);
	~String();

	String(const String &other);
	String &operator=(const String &other);

	void append(const String &other);

	struct Substring {
		Substring(String s, size_t ind) {
			sub_size = s.size - ind;
			ind1 = ind;
			str_ = new char[sub_size + 1];
			for (size_t j = 0, i = ind; i <= s.size; i++, j++)
				str_[j] = s.str[i];
		}

		~Substring() {
			delete[] str_;
		};

		String operator[](size_t ind) {
			sub_size = ind - ind1;
			char * t_str = new char[sub_size + 1];
			size_t i = 0;
			for (i = 0; i < sub_size; i++)
				t_str[i] = str_[i];
			t_str[i] = '\0';
			delete[] str_;
			str_ = t_str;
			return String(str_);
		}
	private:
		size_t sub_size;
		size_t ind1;
		char * str_;
	};

	Substring operator[](size_t index) const {
		return Substring(*this, index);
	}

	size_t size;
	char *str;
};