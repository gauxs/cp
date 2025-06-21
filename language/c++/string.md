# 📚 C++ std::string

## 1. Find
``` cpp
string s = "Welcome to GfG!";
    string sub = "hello";
	
  	// Checking if sub is present in s
  	int res = s.find(sub);
	if (res != string::npos)
      	cout << res;
  	else
      	cout << sub << " NOT found.";
```