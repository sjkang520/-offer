#include <cstdlib>
#include <cstdio>
#include <cstring>
// ����ָOffer�����������Թپ������ͱ���⡷����
// ���ߣ��κ���
//==================================================================

// ������5���滻�ո�
// ��Ŀ����ʵ��һ�����������ַ����е�ÿ���ո��滻��"%20"���������롰We are happy.����
// �������We%20are%20happy.����

//������
//		str--��Ҫ�滻���ַ���
//		length--�ַ�����str�������������ڻ�����ַ���str��ʵ�ʳ���

//˼·һ������һ�������ַ����飬�Ƚ�ԭ�ַ������Ƶ������飬�ٰ����鸴�ƻ�����ԭ���鸲��
//�����ո�ʱ�滻��%20
void replaceSpace(char *str, int length) {
	if (str == nullptr || length <= 0)
		return;
	int str_length = strlen(str);
	// char *temp=(char*)malloc(sizeof(char)*length+1);
	 char *temp=new char[str_length+1];
	//char temp[str_length + 1];
	strcpy(temp, str);
	int index = 0;
	for (int n = 0; n<str_length; n++)
	{
		if (temp[n] == ' ')
		{
			str[index++] = '%';
			str[index++] = '2';
			str[index++] = '0';
		}
		else
			str[index++] = temp[n];
	}
	str[index] = '\0';
	 delete [] temp;
	//free(temp);
}
//�㷨����
void ReplaceBlank(char str[], int length)
{
	if (str == nullptr || length <= 0)
		return;
	int countBlank = 0;
	int str_length = strlen(str);
	for (int i = 0; i < str_length; i++)
	{
		if (str[i] == ' ')
			countBlank++;
	}
	int index_original = str_length;
	int index_new = str_length + 2 * countBlank ;
	if (index_original > index_new)
		return;
	while (index_original != index_new)
	{
		if (str[index_original] == ' ')
		{
			str[index_new--] = '0';
			str[index_new--] = '2';
			str[index_new--] = '%';
		}
		else
			str[index_new--] = str[index_original];
		index_original--;
	}
}