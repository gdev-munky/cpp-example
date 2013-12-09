

class UpperTriMatrix
{
public:
	//Конструктор
	UpperTriMatrix(int sz);
	//Деструктор
	~UpperTriMatrix();

	//Сама матрица (указатель на указатель на тип float)
	float **m;
	//Размер матрицы (матрица квадратная по условию)
	int size;

	//Обращение к [i, j]ому элементу (индексация с нуля!)
	float getv(int i, int j);
	void setv(int i, int j, float v);

	//умножение на скаляр
	void mul(float a);

	//Возвращает определитель
	float det();


};
static UpperTriMatrix* mul (UpperTriMatrix* A, float B)
{
	UpperTriMatrix* nM = new UpperTriMatrix(A->size);
	for (int i = 0; i < A->size; i++)
	for (int j = i; j < A->size; j++)
	{
		nM->setv(i, j, A->getv(i, j)*B);
	}
	return nM;
}
