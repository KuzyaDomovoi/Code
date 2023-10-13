#include <stdio.h>

// struct is a keyword used to storing coordinates of points in the thtee-dimentional space with different cell addresses;

struct tag_point { // struct - is the keyword of a new datatype (composite), tag_point - is an optional name;
    int x; // 4 bytes;     int x; int y; int z; - are the set of vars;
    int y; // 4 bytes;
    int z; // 4 bytes;
};

struct tag_point1 { 
    int x1;  
    int y1; 
    int z1; 
};

struct tag_point2 { 
    int x2; 
    int y2; 
    int z2;
};

struct tag_point3 { 
    int x3; 
    int y3; 
    int z3; 
};

struct tag_point4 { 
    int x4; 
    int y4; 
    int z4; 
};

int main(void)
{
    struct tag_point pt; // var pt is a composite datatype of points x, y, z in the three-dim space 
    pt.x = 1; // is int x inside the struct tag_point for var pt;
    pt.y = 2; // is int y inside the struct tag_point for var pt;
    pt.z = 3; // is int z inside the struct tag_point for var pt;
    size_t sz_pt = sizeof(pt);
    size_t sz_st = sizeof(struct tag_point); // so that is struct tag_point is decl as var pt;
    printf("x = %d, y = %d, z = %d\n", pt.x, pt.y, pt.z);    
    printf("sz_pt = %ld\nsz_st = %ld\n", sz_pt, sz_st);

    struct tag_point1 pt1 = {10, 20, 30};
    size_t sz_pt1 = sizeof(pt1);
    printf("x1 = %d, y1 = %d, z1 = %d\n", pt1.x1, pt1.y1, pt1.z1);
    printf("sz_pt1 = %ld\n", sz_pt1);

    struct tag_point2 pt2 = {10};
    size_t sz_pt2 = sizeof(pt2);
    printf("x2 = %d, y2 = %d, z2 = %d\n", pt2.x2, pt2.y2, pt2.z2);
    printf("sz_pt2 = %ld\n", sz_pt2);

    struct tag_point3 pt3 = {};
    size_t sz_pt3 = sizeof(pt3);
    printf("x3 = %d, y3 = %d, z3 = %d\n", pt3.x3, pt3.y3, pt3.z3);
    printf("sz_pt3 = %ld\n", sz_pt3);

    struct tag_point4 pt4 = {.y4 = -1, .x4 = 2};
    size_t sz_pt4 = sizeof(pt4);
    printf("x4 = %d, y4 = %d, z4 = %d\n", pt4.x4, pt4.y4, pt4.z4);
    printf("sz_pt4 = %ld\n", sz_pt4);
    return 0;
}
