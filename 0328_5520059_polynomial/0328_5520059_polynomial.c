#include <stdio.h>
#define MAX_DEGREE 101

typedef struct {
    int degree;
    float coef[MAX_DEGREE];
} polynomial;

polynomial poly_multiply(polynomial A, polynomial B) {
    polynomial C;
    C.degree = A.degree + B.degree; // 결과 다항식C의 최고차항

    for (int i = 0; i <= C.degree; i++) {     // 결과 다항식C의 계수 초기화 ㅁx^d 할때 ㅁ을 0으로 초기화 해둬야 쓰레기값 안들어옴 
        C.coef[i] = 0;
    }

    int Apos = 0, Bpos = 0, Cpos = 0; // 다항식 A, B, C의 위치를 나타내는 인덱스 변수
    int degree_a = A.degree; // 다항식 A의 최고 차수
    int degree_b = B.degree; // 다항식 B의 최고 차수

    while (Apos <= A.degree) {
        Bpos = 0; // 다항식 B의 인덱스 초기화
        while (Bpos <= B.degree) {
            C.coef[Apos + Bpos] = C.coef[Apos + Bpos] + A.coef[Apos] * B.coef[Bpos]; // 다항식A와 B의 각 항의 곱을 계산하고 결과 다항식인 C에 더함
            Bpos++;
        }
        Apos++; // A 다항식의 인덱스 증가
    }

    return C;
}

void print_poly(polynomial p) {
    for (int j = p.degree; j > 0; j--) {
        printf("%3.1fx^%d + ", p.coef[p.degree - j], j);
    }
    printf("%3.1f\n", p.coef[p.degree]);
}

int main(void) {

    polynomial a = { 3, {4, 3, 2, 1} }; // 4x^3 + 3x^2 + 2x^1 + 1
    polynomial b = { 2, {3, 2, 8} };    // 3x^2 + 2x^1 + 8
    // polynomial a = {6, {7, 0, 0, 5, 9, 0, 1} };  // 7x^6 + 5x^3 + 9x^2 + 1
    // polynomial b = {3, {5, 2, 1, 10} };    // 5x^3 + 2x^2 + 1x^1 + 10
    polynomial c;

    print_poly(a);
    print_poly(b);

    c = poly_multiply(a, b);

    printf("==================================================\n");
    print_poly(c);

    return 0;
}