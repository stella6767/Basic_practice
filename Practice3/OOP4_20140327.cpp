#include <iostream>
#include <string>
#include <cstring> //strstr 함수가 선언된

using namespace std;

int main()
{
	/*int num=0,emp=0,chr=0,i; //변수 선언 초기화
	char str[20]; //20자 이내 문자 배열공간

	cout<<"문자열을 입력(20자 이내): ";
	gets(str); //문자열 입력함수

	for(i=0;str[i]!='\0';i++){ //'\0'은 문자열 끝나고 마지막에 나옴
		if(('A'<=str[i]&&str[i]<='Z')||('a'<=str[i]&&str[i]<='z'))//알파벳 확인
			chr++;
		else if('0'<=str[i]&&str[i]<='9')//숫자
			num++;
		else if(str[i]==' ')//공백
			emp++;
	}
	cout<<"알파벳 수:"<<chr<<endl;
	cout<<" 숫자 수:"<<num<<endl;
	cout<<" 공백 수:"<<emp<<endl;

	int num=0,i; //공백 계산할 변수
	char str[20];

	cout<<"문자열 입력(20자 이내): ";
	gets(str);

	for(i=0; str[i]!='\0'; i++){ //문자열 첫번째 공간부터 마지막까지 반복
		if(str[i]==' ')	//만약 이 공간이 공백이라면
			num++; //+1
	}
	cout<<num+1; //공백 합친 숫자에 +1
		*/

	char one[100] = { 0, };
	char find[10] = { 0, };
	char* first;
	char* last;

	char change[10] = { 0, };
	char tmp[10] = { 0, };

	int i;

	cout << "기존 문자열 : ";
	cin.getline(one, 100); //cin.getline(char*,int cnt)는 띄워쓰기까지 포함하여 배열에 넣습니다.
								//사용자가 엔터 치기 전까지의 모든 문자열을 담게됩니다.

	cout << "찾을 문자열 : ";
	cin.getline(find, 10);
	cout << "바꿀 문자열 : ";
	cin.getline(change, 10);

	for (i = 0; i < strlen(one); i++) { //one 이란 배열을 모두 훑어봅니다.
		first = &one[i]; // 훑어보는 포인터 first.

		if (strncmp(first, find, strlen(find)) == 0) { //first에서부터 찾는 단어의 크기까지 단어가 같다면
		 //이제부터 바꿔버립니다.

			last = &one[i + strlen(find)]; // last에 바꿔버릴 단어 이후의 시작을 찍습니다.
			strncpy(tmp, change, strlen(change)); // last 이후로 바꿀 문자열을 넣고,
			strncat(tmp, last, strlen(last)); // 그이후도 다 넣습니다.
			strncpy(first, tmp, strlen(tmp)); // 바꿀 문자열의 첫 위치부터 tmp를 넣으면 바뀝니다.

			memset(tmp, '\0', sizeof(tmp)); // 임시배열 초기화
		}
	}
	cout << "결과 문자열 : ";
	cout << one << endl;

	return 0;
}