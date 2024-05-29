#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int coeff;
    int expo;
    struct Node *next;
};
typedef struct Node *P;
typedef struct Node *Position;

P createPoly(P poly)
{
    P poly = malloc(sizeof(struct Node));
    poly->next = NULL;
    poly->expo = -1;
    return poly;
}
void Insert(P poly, int coeff, int expo)
{
    while (poly != NULL && poly->expo >= expo)
    {
        poly = poly->next;
    }
    if (poly->expo == expo)
    {
        poly->coeff += coeff;
    }
    else
    {
        Position newItem = malloc(sizeof(struct Node));
        newItem->coeff = coeff;
        newItem->expo = expo;
        newItem->next = poly->next;
        poly->next = newItem;
    }
}
void Display(P poly)
{
    poly = poly->next;
    while (poly != NULL)
    {
        printf("%dx^%d ", poly->coeff, poly->expo);
        poly = poly->next;
    }
    printf("\n");
}
void sum(P poly1, P poly2, P polysum)
{
    poly1 = poly1->next;
    poly2 = poly2->next;
    while (poly1 != NULL)
    {
        Insert(polysum, poly1->coeff, poly1->expo);
        poly1 = poly1->next;
    }
    while (poly2 != NULL)
    {
        Insert(polysun, poly2->coeff, poly2->expo);
        poly2 = poly2->next;
    }
}
void multi(P poly1, P poly2, P polymulti)
{
    poly1 = poly1->next;
    poly2 = poly2->next;
    while (poly1 != NULL)
    {
        while (poly2 != NULL)
        {
            Insert(polymulti, poly1->coeff * poly2->coeff, poly1->expo + poly2->expo)
                poly2 = poly2->next;
        }
        poly1 = poly1->next;
        poly2 = temp;
    }
}
int main()
{
    P poly1 = createPoly();
    P poly2 = createPoly();
    P polysum = createPoly();
    P polymulti = createPoly();

    Insert(poly1, 5, 5);
    Insert(poly1, 4, 2);
    Insert(poly1, -10, 1);
    Insert(poly1, 7, 0);
    Insert(poly2, 5, 4);
    Insert(poly2, 4, 3);
    Insert(poly2, -10, 2);
    Insert(poly2, 5, 0);

    sum(poly1, poly2, polysum);
    multi(poly1, poly2, polymulti);
}
/* Poly
#include <stdio.h>
#include <stdlib.h>
#define max 100
struct polynomial{
    unsigned highest;
    int coeff_array[max+1];
};
typedef struct polynomial *P;
void makezero(P poly){
    poly->highest = 0;
    for(int i = 0;i<=max;i++){
        poly->coeff_array[i] = 0 ;
    }
}
unsigned Max(unsigned a,unsigned b){
    return a>b?a:b; // a > b tra ve a nguoc lai tra ve b
}
void sum(P poly1,P poly2,P polysum){
    makezero(polysum);
    polysum->highest = Max(poly1->highest,poly2->highest);
    for(int i = 0 ;i<=polysum->highest;i++){
        polysum->coeff_array[i] = poly1->coeff_array[i] + poly2->coeff_array[i];
    }
}
void prod(P poly1,P poly2 , P polyprod){
    makezero(polyprod);
    polyprod->highest = poly1->highest + poly2->highest;
    for(int i = 0;i<=poly1->highest;i++){
        for(int j = 0;j<=poly2->highest;j++){
            polyprod->coeff_array[i+j] += poly1->coeff_array[i]*poly2->coeff_array[j];
        }
    }
}
void Display(P poly){
    for(int i = poly->highest;i>=0;i--){
        if(i==0){
            if(poly->coeff_array[i]<0)
                printf(" - %d",abs(poly->coeff_array[i]));
            else{
                printf(" + %d",abs(poly->coeff_array[i]));
            }
        }else{
            if(poly->coeff_array[i]<0){
                if(i == poly->highest){
                    printf("%dx^%d",poly->coeff_array[i],i);
                }else
                    printf(" - %dx^%d",abs(poly->coeff_array[i]),i);
        }else{
            if(i == poly->highest){
                printf("%dx^%d",poly->coeff_array[i],i);
            }else
                printf(" + %dx^%d",poly->coeff_array[i],i);
        }
        }

    }
    printf("\n");
}
int main(){
    P poly1 = malloc(sizeof(struct polynomial));
    P poly2 = malloc(sizeof(struct polynomial));
    P polysum = malloc(sizeof(struct polynomial));
    P polyprod = malloc(sizeof(struct polynomial));

    makezero(poly1);
    makezero(poly2);

    poly1->highest = 2;
    poly1->coeff_array[0] = -8;poly1->coeff_array[1] = 8;poly1->coeff_array[2] =-8;
    poly2->highest = 3;
    poly2->coeff_array[0] = -9;poly2->coeff_array[1] = 9;poly2->coeff_array[2] =-9;poly2->coeff_array[3] = 9;

    Display(poly1);
    Display(poly2);

    sum(poly1,poly2,polysum);
    prod(poly1,poly2,polyprod);
    printf("SUM : ");
    Display(polysum);
    printf("\n");
    printf("MULTIPLY");
    Display(polyprod);

    return 0;
}*/
////////////////////////////////////////
/*xây dựng Stack bằng cách sử dụng danh sách liên kết
#include <stdio.h>
#include <stdlib.h>
struct Element{
    char *name;
    int ID;
};
struct Node
{
    struct Node *next;
    struct Element info;
};
typedef struct Node *Stack;
typedef struct Node *StackNode ;
Stack createStack(){
    Stack S = malloc(sizeof(struct Node )); // Tạo Stack (giống header)
    S->next = NULL;
    return S;
}
void push(Stack S,struct Element x){ // them mot element vao Stack
    StackNode node = malloc(sizeof(struct Node ));
    node->info = x ;
    node->next = S->next;
    S->next = node;
}
int IsEmpty(Stack S){
    return S->next == NULL; // nếu s->next == null thì trả về 1 , sai thì 0
}
void Display(Stack S){
    if(IsEmpty(S)){
        printf("Stack is EMPTY \n");
    }else{
        S = S->next;
        while(S!=NULL){
            printf("%s ID:%d\n",S->info.name,S->info.ID);
            S = S->next;
        }
    }
}
void PopOut(Stack S){ //lấy ra stack đầu tiên
    if(IsEmpty(S)){
        printf("Stack is EMPTY \n");
    }else{
        StackNode first = S->next;
        S->next = S->next->next;
        free(first);
    }
}
Stack top(Stack S){
    if(IsEmpty(S)){
        printf("Stack is EMPTY \n"); // Trả về Stack đầu mới sau khi xóa
    }else{
        return S->next;
    }
}
int main(){
    Stack S = createStack();
    struct Element  a,b,c;
    a.ID = 101101010, a.name = "AI Machinius";
    b.ID = 111001011, b.name = "Artificial Intelligence";
    c.ID = 100110101, c.name = "Technolius";
    push(S,a),push(S,b),push(S,c);

    Display(S);

    PopOut(S);
    StackNode node = top(S);
    printf("Information of the new top\n");
    printf("%s ID:%d \n",node->info.name,node->info.ID);
}
//////////////////////////////////////////
// danh sách liên kết đôi . có sử dụng header
/*#include <stdio.h>
#include <stdlib.h>
struct ElementType{
    char *name ;
    int ID;
};
typedef struct ElementType sv;
struct Node
{
    sv information;
    struct Node *next;
    struct Node *prev; // tro toi con tro sau no
};
typedef struct Node *List;
typedef struct Node *Position;
List createHeader(){ // tao headerNode
    List headerNode ;
    headerNode = malloc(sizeof(struct Node ));
    headerNode ->next = NULL;
    return headerNode;
}
Position Insert(sv x, Position p ){
    Position newItem ;
    newItem = malloc (sizeof (struct Node ));
    newItem ->information = x;

    newItem->next = p ->next ;
    newItem->prev = p ;
    p->next = newItem;

    if(newItem->next !=NULL){
        newItem->next->prev = newItem ;
    }
    return newItem ; // để biết được nút vừa chèn vào
}
Position Delete( Position p){
    p->prev->next = p->next;
    if(p->next != NULL){
        p->next->prev = p->prev;
    }
    free(p); // không dùng đến p nên giải phóng
}
void Display(List fp){
    int count = 1 ;
    fp = fp ->next;
    while(fp!=NULL){
        printf("%d: %s %d \n",count , fp->information.name,fp->information.ID);
        fp = fp->next;
        count ++;
    }
}
Position Find(List fp , int ID){
    //fp = fp ->next;
    while(fp!=NULL && fp->information.ID != ID){
        fp = fp->next;
    }
    return fp;
}
int main(){
    List fp = createHeader();
    Position p = NULL;
    sv a , b, c;

    a.ID = 101101010, a.name = "AI Machinius";
    b.ID = 111001011, b.name = "Artificial Intelligence";
    c.ID = 100110101, c.name = "Technolius";

    p = Insert(a,fp);
    p = Insert(b,p);
    p = Insert(c,p);

    Display(fp);

    p = Find(fp,101101010);
    if(p!=NULL){
        printf("Found  ID:%d Name:%s \n",p->information.ID,p->information.name);
    }else{
        printf("Not Found\n");
    }
    Delete(p);
    printf("After Delete Student Have Been Found\n");
    Display(fp);
}
*/
/* chèn vào danh sách . Sử dụng header để không cần kiểm tra danh sách đang rỗng hay không
#include <stdio.h>
#include <stdlib.h>
struct ElementType{
    char *name;
    int ID;
};
typedef struct ElementType sv;
struct Node{
    struct Node *next;
    struct ElementType infomation;
};
typedef struct Node *Position; // bat cu ten gi cung duoc nhung can phu hop voi muc dich cua minh
typedef struct Node *List;
Position Insert(sv x,Position p){ // khong can List fp vi khong can ktr co phai la NULL hay khong
    Position newItem ;
    newItem = malloc(sizeof(struct Node));
    newItem->infomation = x;

    newItem->next = p->next; // chen vao sau p
    p->next = newItem;

    return newItem;
}
Position Find(List fp,int ID){
    fp = fp->next ; // Khong can duyet qua NULL
    while(fp!=NULL && fp->infomation.ID != ID){
        fp = fp->next;
    }
    return fp;
}
List creatHeader(){
    List headerNode ;
    headerNode = malloc(sizeof(struct Node ));
    headerNode->next = NULL;
    return headerNode;
}
void Display(List fp){
    int count = 1;
    fp = fp->next;
    while(fp != NULL){
        printf("%d: %s %d \n",count, fp->infomation.name,fp->infomation.ID);
        fp = fp->next;
        count ++;
    }
}
int main(){
    List fp = creatHeader();
    sv a,b,c;

    a.ID = 101101010, a.name = "AI Machinius";
    b.ID = 111001011, b.name = "Artificial Intelligence";
    c.ID = 100110101, c.name = "Technolius";

    Position p = NULL;

    p = Insert(a,fp); // can them phan tu dau tien vao fp
    p = Insert(b,p);
    p = Insert(c,p);

    Display(fp);

    p = Find(fp,111001011);

    if(p != NULL){
        printf("Found  ID:%d Name:%s ",p->infomation.ID,p->infomation.name);
    }else{
        printf("Not Found ");
    }


}*/
/////////////////////////////////////////
/* Chèn vào danh sách liên kết
#include <stdio.h>
#include <stdlib.h>
struct ElementType
{
    char *name;
    int age;
};
typedef struct ElementType sv;
struct Node
{
    struct Node *next;
    struct ElementType value;
};
typedef struct Node *List;
typedef struct Node *Position;

Position Insert(List *fp,sv x,Position p){
    Position newItem ;
    newItem = malloc(sizeof(struct Node));
    newItem->value = x;
    if(*fp == NULL || p == NULL){
        newItem->next = *fp;
        *fp = newItem;
    }else{
        newItem->next = p->next;
        p->next = newItem;
    }
    return newItem;
}
void Display(List fp){
    int count = 1;
    while(fp!= NULL){
        printf("%d: %s %d \n",count,fp->value.name,fp->value.age);
        fp = fp->next;
        count++;
    }
}
int main(){
    List fp = NULL; // vi tri node ban dau bang NULL
    Position p; // khai bao vi tri can chen
    sv a,b,c; // khai bao sinh vien

    a.age = 10; a.name = "Nguyen Van A"; // cap nhat thong tin
    b.age = 39; b.name = "Nguyen Van B";
    c.age = 29; c.name = "Nguyen Van C";

    p = Insert(&fp,a,p);
    p = Insert(&fp,b,p);
    p = Insert(&fp,c,p);

    Display(fp);
}
*/
//////////////////////////////////////////////////////
// Chèn vào danh sách Mảng
//  #include <stdio.h>
//  #include <stdlib.h>
//  #include <time.h>
//  struct Sinhvien
//  {
//      int age;
//      char *name;
//  };
//  typedef struct Sinhvien *sv; // con trỏ sv trỏ đến struct Sinhvien
//  struct ListInfo
//  {
//      unsigned count ; // số lượng phần tử trong mảng hiện tại
//      unsigned max ;
//      sv list;
//  };typedef struct ListInfo *svlist;
//  #define svlist struct ListInfo* // con trỏ sv trỏ đến struct ListInfo
//  #define Position int
//  void Insert(svlist a,sv b , Position c){  //Pisition c là vị trí muốn chèn
//      Position current;
//      if(c>a->max|| a->count == a->max)exit(1);
//      current = a->count;
//      while(current!= c){
//          a->list[current] = a->list[current - 1];
//          current -- ;
//      }
//      a->list[current] = *b;
//      a->count++;
//  }
//  void Display(svlist a){
//      for(int i = 0 ;i <a->count;i++){
//          printf("%d: %s %d \n",i+1,a->list[i].name,a->list[i].age);
//      }
//  }
//  int main()
//  {
//      svlist svl; // Tạo danh sách

//     svl = (svlist)malloc(sizeof(struct ListInfo)); // cấp phát
//     svl->count = 0 ;
//     svl->max = 100;
//     svl->list = (sv)malloc(svl->max*sizeof(struct Sinhvien));

//     sv sinhvien1 = (sv)malloc(sizeof(struct Sinhvien)); // Tạo sinh viên
//     sinhvien1->name="Nguyen Van A"; sinhvien1->age = 10;
//     sv sinhvien2 = (sv)malloc(sizeof(struct Sinhvien));
//     sinhvien2->name = "Nguyen Van B"; sinhvien2->age = 20;

//     Insert(svl,sinhvien1,2);
//     Insert(svl,sinhvien2,3);// chú ý không thể chèn quá count

//     Display(svl);

// }
//////////////////////////////////////////////////////////////////
// Danh sách liên kết đơn
// #include <stdio.h>
// #include <stdlib.h>

// struct Student
// {
//     int age ;
//     char *name;
// };
// #define sv struct Student
// struct Node
// {
//     struct Node *next;
//     sv *Element;
// };
// int main(){
//     sv a;
//     sv b; // khai bao cac id
//     sv c;
//     struct Node *nodea;
//     struct Node *nodeb; // khai bao node
//     struct Node *nodec;
//     struct Node *nodeP;

//     a.age = 10; a.name = "Tokuda";
//     b.age = 20; b.name = "Eimifukuda"; // gan du lieu
//     c.age = 30; c.name = "Marigawa";

//     nodea = malloc(sizeof(struct Node));
//     nodeb = malloc(sizeof(struct Node)); // cap phat bo nho
//     nodec = malloc(sizeof(struct Node));

//     nodea->next = nodeb ; nodea->Element = &a;
//     nodeb->next = nodec ; nodeb->Element = &b; // xep cac node
//     nodec->next = NULL ; nodec->Element = &c;
//     nodeP = nodea;
//     while(nodeP!=NULL){
//         if(nodeP->next == NULL){
//             printf("Dia chi hien tai %d , Sinh vien %s , tuoi %d Ket thuc !\n",nodeP,nodeP->Element->name,nodeP->Element->age);
//         }else{
//             printf("Dia chi hien tai %d , Sinh vien %s , tuoi %d , dia chi cua sinh vien tiep theo %d\n",nodeP,nodeP->Element->name,nodeP->Element->age,nodeP->next);
//         }
//         nodeP = nodeP->next;
//     }
// }
