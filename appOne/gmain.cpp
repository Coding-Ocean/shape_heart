#include"libOne.h"
int createTriangle() {
    struct SHAPE_VERTEX vertices[3];
    vertices[0].x = 0;
    vertices[0].y = -0.8;
    vertices[1].x = 0.5;
    vertices[1].y = 1;
    vertices[2].x = -0.5;
    vertices[2].y = 1;
    return createShape(vertices, 3);
}
int createPolygon() {
    const int NUM = 5;
    struct SHAPE_VERTEX vertices[NUM];
    float deg = 360.0f / NUM;
    angleMode(DEGREES);
    for (int i = 0; i < NUM; i++) {
        vertices[i].x = sin(deg*i);
        vertices[i].y = -cos(deg*i);
    }
    return createShape(vertices, NUM);
}
int createStar() {
    const int NUM = 10;
    struct SHAPE_VERTEX vertices[NUM];
    float deg = 360.0f / NUM;
    angleMode(DEGREES);
    for (int i = 0; i < NUM; i++) {
        float radius = 0.5f + 0.5f * (i%2);
        vertices[i].x = sin(deg * i) * radius;
        vertices[i].y = cos(deg * i) * radius;
    }
    return createShape(vertices, NUM);
}
int createHeart() {
    const int NUM = 90;
    struct SHAPE_VERTEX vertices[NUM];
    float deg = 360.0f / NUM;
    angleMode(DEGREES);
    for (int i = 0; i < NUM; i++) {
        float t = deg * i;
        vertices[i].x = 
            pow( sin(t), 3 );
        vertices[i].y = -(
            13 * cos(t) -
            5 * cos(2 * t) -
            2 * cos(3 * t) -
            1 * cos(4 * t) ) / 16;
    }
    return createShape(vertices, NUM);
}
void gmain() {
    window(1600, 1000);
    int triangleIdx = createTriangle();
    int polygonIdx = createPolygon();
    int starIdx = createStar();
    int heartIdx = createHeart();
    float deg = 0;
    angleMode(DEGREES);
    while (notQuit) {
        //deg += 1;
        clear(200);
        strokeWeight(5);
        fill(0, 255, 0);
        shape(triangleIdx, 300, 500, deg, 200);
        fill(0, 255, 255);
        shape(polygonIdx, 600, 500, deg, 200);
        fill(255, 255, 0);
        shape(starIdx, 900, 500, deg, 200);
        fill(255, 0, 0);
        shape(heartIdx, 1200, 500, deg, 200);
    }
}
