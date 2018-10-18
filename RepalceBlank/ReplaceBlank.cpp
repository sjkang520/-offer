#include <cstdlib>
#include <cstdio>
#include <cstring>
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

// 面试题5：替换空格
// 题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，
// 则输出“We%20are%20happy.”。

//参数：
//		str--需要替换的字符串
//		length--字符数组str的总容量，大于或等于字符串str的实际长度

//思路一：申请一个辅助字符数组，先将原字符串复制到此数组，再把数组复制回来将原数组覆盖
//遇到空格时替换成%20
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
//算法二：
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