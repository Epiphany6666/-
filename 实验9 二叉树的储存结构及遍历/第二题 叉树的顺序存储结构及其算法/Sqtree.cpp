#include"Sqtree.h"
extern ElemType N1;

void InitBiTree(SqBiTree& b) {
	int i = 0;
	for (i = 0; i < MaxSize; i++) {
		b[i] = N1;
	}
}

void CreateBiTree(SqBiTree& b, ElemType* t) {
	int i = 0;
	int j = 1;
	for (i = 0; t[i] != '\0'; i++) {
		b[j] = t[i];
		j++;
	}
}

ElemType Parent(SqBiTree b, ElemType t) {
	if (b[1] == N1) {
		return 0;
	}
	int i = 0;
	for (i = 1; i < MaxSize; i++) {
		if (b[i] == t) {
			return b[i / 2];
		}
	}
	return N1;
}

//ElemType lchild(SqBiTree b, ElemType t) {
//	if (b[1] != N1) {
//		int i = 0;
//		for (i = 1; i < MaxSize; i++) {
//			if (b[i] == t) {
//				return b[2*i];
//			}
//			else
//			{
//				return N1;
//			}
//		}
//	}
//	else {
//		return N1;
//	}
//}

ElemType lclild(SqBiTree b, ElemType t) {
	int i = 0;
	for (i = 1; i < MaxSize; i++) {
		if (b[i] == t) {
			return b[2 * i];
		}
		else
		{
			return N1;
		}
	}
	return N1;
}


ElemType rchild(SqBiTree b, ElemType t) {
	int i = 0;
	for (i = 1; i < MaxSize; i++) {
		if (b[i] == t) {
			return b[2 * i];
		}
		else
		{
			return N1;
		}
	}
	return N1;
}

//ElemType rchild(SqBiTree b, ElemType t) {
//	if (b[1] != N1) {
//		int i = 0;
//		for (i = 1; i < MaxSize; i++) {
//			if (b[i] == t) {
//				return b[2 * i];
//			}
//			else
//			{
//				return N1;
//			}
//		}
//	}
//	else {
//		return N1;
//	}
//}