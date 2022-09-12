
#include <iostream>
#include <string.h>

using namespace std;

string encrypt(string text, int shift) {

	string res = "";

	for (int i = 0; i < text.length(); i++) {
		if (isupper(text[i]))
			res += char(int(text[i] + shift - 65) % 26 + 65);
		else
			res += char(int(text[i] + shift - 97) % 26 + 97);
	}
	return res;

}

string decrypt(string cipher, int sh) {

	string res = "";

	for (int i = 0; i < cipher.length(); i++) {
		if (isupper(cipher[i]))
			res += char(int(cipher[i] + sh - 65) % 26 + 65);
		else
			res += char(int(cipher[i] + sh - 97) % 26 + 97);
	}
	return res;
}
int main()
{
	setlocale(LC_ALL, "Russian");

	string text;
	int sh;

	bool validate = true;

	cout << "Введите ключ в диапозоне 0 - 25" << endl;
	cin >> sh;
	while (validate) {
		if (sh <= 0 || sh > 25) {
			cout << "Ваш ключ должен быть в диапозоне 0 - 25" << endl;
			cin >> sh;
		}
		else if (sh != 0 && sh < 25) {
			cout << "Введите сообщение: " << endl;
			cin >> text;
			if (text != "") {
				string cipher = encrypt(text, sh);
				cout << "\nЗашифрованный текст сообщения: " << "'" << text << "'" << " is : " << cipher;
				string recoveredMessage = decrypt(cipher, 26 - sh);
				cout << "\nРассшиврованный текст сообщения: " << recoveredMessage;
				cout << "\n\n";
				validate = false;
			}
		}
	}

}