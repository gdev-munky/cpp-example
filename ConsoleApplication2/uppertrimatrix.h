

class UpperTriMatrix
{
public:
	//�����������
	UpperTriMatrix(int sz);
	//����������
	~UpperTriMatrix();

	//���� ������� (��������� �� ��������� �� ��� float)
	float **m;
	//������ ������� (������� ���������� �� �������)
	int size;

	//��������� � [i, j]��� �������� (���������� � ����!)
	float getv(int i, int j);
	void setv(int i, int j, float v);

	//��������� �� ������
	void mul(float a);

	//���������� ������������
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
