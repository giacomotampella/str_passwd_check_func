/*	
	Modificare ed estendere l'esercizio in modo tale da creare:
	1) la function str_passwd_check_len che restituisca true se la lunghezza della stringa è compresa tra l'intervallo l_min, l_max (passati come parametri).
	2) la function str_passwd_check_upper che restituisca il numero di lettere maiuscole presenti nella stringa.
	3) la function str_passwd_check_lower che restituisca il numero di lettere minuscole presenti nella stringa.
	4) la function str_passwd_check_numeric che restituisca il numero di caratteri numerici presenti nella stringa.
	5) la function str_passwd_check che, utilizzando le functions precedenti, restituisca true se la stringa passata (parametro):
	5.1) ha lunghezza compresa tra l_min, l_max (parametri)
	5.2) contiene almeno n_upper lettere maiuscole (parametro)
	5.3) contiene almeno n_lower lettere minuscole (parametro)
	5.4) contiene almeno n_numeric numeri (parametro)
	5.5) contiene almeno n_other caratteri non alfanumerici (parametro)
	
	Se tutte le precedenti condizioni sono verificate restituirà 0 altrimenti restituirà il numero corrispondente al requisito non verificato (1..5)
*/

#include <iostream>
#include <string.h>

using namespace std;

const int L_MIN = 8;
const int L_MAX = 32;
const int N_UPPER = 1;
const int N_LOWER = 5;
const int N_NUMERIC = 1;
const int N_OTHER = 1;

char str[L_MAX+1];

bool str_passwd_check_len (char str[], int l_min, int l_max) {
	int l = strlen(str);
	return (l_min<=l && l<=l_max);
}

int str_passwd_check_char (char str[], char c_min, char c_max){
	int n = 0;
	for (int i = 0; str[i]!='\0'; i++) {
		if (str[i]>=c_min && str[i]<=c_max){
			n++;
		}
	}
	return n;
}

int str_passwd_check_upper (char str[]) {
	return str_passwd_check_char(str, 'A', 'Z');
}

int str_passwd_check_lower (char str[]) {
	return str_passwd_check_char(str, 'a', 'z');
}

int str_passwd_check_numeric (char str[]) {
	return str_passwd_check_char(str, '0', '9');
}

int str_passwd_check (char str[], int l_min, int l_max, int n_upper, int n_lower, int n_numeric, int n_other) {
	if (!str_passwd_check_len(str, l_min, l_max)) {
		return 1;
	}
	int nu = str_passwd_check_upper(str);
	if (nu<n_upper) {
		return 2;
	}
	int nl = str_passwd_check_lower(str);
	if (nl<n_lower) {
		return 3;
	}	
	int nn = str_passwd_check_numeric(str);
	if (nn<n_numeric) {
		return 4;
	}
	if (strlen(str) - nu - nl - nn < n_other) {
		return 5;
	}
	return 0; 
	
}

int main () {
	int result;
	cout << "La password deve soddisfare tutti i campi seguenti: " << endl << endl;
	cout << "- Deve contenere minimo " << L_MIN << " caratteri fino ad un max. di " << L_MAX << " caratteri;" << endl;
	cout << "- Deve contenere almeno " << N_UPPER << " caratteri maiuscoli;" << endl;
	cout << "- Deve contenere almeno " << N_LOWER << " caratteri minuscoli;" << endl;
	cout << "- Deve contenere almeno " << N_NUMERIC << " caratteri numerici;" << endl;
	cout << "- Deve contenere almeno " << N_OTHER << " simboli;" << endl << endl;
	do {
		cout << "PASSWORD: ";
		cin.getline(str, L_MAX+1);
		cout << endl;
		result = str_passwd_check(str, L_MIN, L_MAX, N_UPPER, N_LOWER, N_NUMERIC, N_OTHER);
		if (result == 1) {
			cout << "La password deve contenere minimo " << L_MIN << " caratteri fino a max. " << L_MAX << " ." << endl << endl;
		} else if (result == 2) {
			cout << "La password deve contenere almeno " << N_UPPER << " caratteri maiuscoli." << endl << endl;
		} else if (result == 3) {
			cout << "La password deve contenere almeno " << N_LOWER << " caratteri minuscoli." << endl << endl;
		} else if (result == 4) {
			cout << "La passeord deve contenere almeno " << N_NUMERIC << " caratteri numerici." << endl << endl;
		} else if (result == 5) {
			cout << "La password deve contenere almeno " << N_OTHER << " simboli." << endl << endl;
		}
	} while (result != 0);
	cout << "OK. Password valida!" << endl << endl;
	system ("PAUSE");
}
