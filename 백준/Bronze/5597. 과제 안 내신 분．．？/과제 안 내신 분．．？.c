
main() {
	int check[30] = { 0, };		//과제 제출한 학생을 체크하는 배열
	for (int i = 0; i < 28; i++) {	//과제 제출한 학생 체크
		int n;
		scanf("%d", &n);
		check[n - 1] = 1;
	}
	for (int i = 0; i < 30; i++)	//과제 미제출 학생 출석번호 출력
		if (check[i] == 0)
			printf("%d\n", i + 1);
}