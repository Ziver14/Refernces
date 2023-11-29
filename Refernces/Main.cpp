#include<iostream>

int mx[10][2];
template <typename T>
void print_arr(T arr[], const int length) {
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;
}

void p_swap(int* pointer1, int* pointer2) {

	int tmp = *pointer1;
	*pointer1 = *pointer2;
	*pointer2 = tmp;
}

void ref_swap(int& reference1,int& reference2) {
	int tmp = reference1;
	reference1 = reference2;
	reference2 = tmp;
}

int& mx_at(int index) {
	return mx[index][1];
}

int& ref_max(int arr[], const int length) {
	int max_index = 0;
	for (int i = 1; i < length; i++)
		if (arr[i] > arr[max_index])
			max_index = i;
	return arr[max_index];
}


int main() {
	setlocale(LC_ALL, "ru");
	//Ссылки
	int n = 7, m;

	
	int& refn = n; //создание ссылки ассоциирущейся с переменной n;

	std::cout << "refn = " << refn << std::endl;

	//Ссылка - это альтернативное имя какой-либо уже существующей переменной. Синтаксический сахар.

	refn = 15;

	//Ссылки, в отличии от указателей, всегда должна быть инициализированна. Нет аналога нейтрального указателя
	//Не существует операторов производящих действия непосредственно с ссылкой.
	//Станадарт С++ не определяет , как компилятор работает с ссылкой, некоторые заменяют ссылку на переменную,некоторые на указатель.
	std::cout << "n = " << n << std::endl;

	//Ссылки как параметры функций.
	n = 7; m = 15;
	std::cout << n << ' '<< m << std::endl;
	//p_swap(&n, &m);//Работает но не удобно.
	ref_swap(n, m);
	std::cout << n << ' ' << m << std::endl;
	

	//Ссылки как результат работы функциий.
	std::cout << "Ввод данных в массив:\n";
	for (int i = 0; i < 10; i++) {
		std::cout << "Элемент №" << i << "->";
		std::cin >> mx[i][0];
		mx_at(i) = mx[i][0];


	}
	std::cout << "Итоговый массив:\n";
	for (int i = 0; i < 10; i++)
		std::cout << mx[i][0] << "\t" << mx_at(i) << std::endl;

	const int size = 5;
	int arr[size]{ 6, 7, 5, 4, 7 };
	print_arr(arr, size);
	std::cout << "Максимум:" << ref_max(arr, size) << std::endl;
	ref_max(arr, size) = 0;
	print_arr(arr, size);

	return 0;
}