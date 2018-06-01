 struct Cls {
 Cls(char c, double d, int i);
 private:
     char c;
     double d;
     int i;
 };



char &get_c(Cls &cls) {
	return *((char *)&cls);
}

double &get_d(Cls &cls) {
	return *((double *)&cls + 1);
}

int &get_i(Cls &cls) {
	return *((int *)&cls + 4);
}
