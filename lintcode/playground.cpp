//#include <iostream>
//#include <vector>
//#include <string>
//#include <cstdio>
//#include <cctype>
//#include <cmath>
//
//int main(int argc, char *args[]) {
//	float person[3] = { 0, 0, 0 }, roster[3] = { 0, 0, 0 };
//	int id, num;
//	char cate;
//	float cash;
//	char c = '\0';
//	while (scanf("%c", &c) != EOF) {
//		if (c == '\n')
//			scanf("%d %d", &id, &num);
//		else {
//			id = c;
//			scanf(" %d", &num);
//		} 
//		for (int i = 0; i < num; ++i) {
//			scanf(" %c %f", &cate, &cash);
//			switch (cate)
//			{
//			case('A'): roster[0] += cash; break;
//			case('B'): roster[1] += cash; break;
//			case('C'): roster[2] += cash; break;
//				default:	break;
//			}
//			person[id - 1] += cash;
//		}
//		c = getchar();
//	}
//	for (int i = 0; i < 3; ++i) {
//		std::cout << person[i] << std::endl;
//	}
//	for (int i = 0; i < 3; ++i) {
//		std::cout << roster[i] << std::endl;
//	}
//	return 0;
//}
//
//
