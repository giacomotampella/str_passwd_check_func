# str_passwd_check_func
string password check with functions in C++

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
