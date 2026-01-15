#include <stdio.h>

int get_roof_area(int width, int roof_height) {
    return width * roof_height;
}

int get_base_area(int width, int height) {
    return width * height;
}

int get_house_area(int height, int width, int roof_height) {

    int roofarea = get_roof_area(width, roof_height);
    int basearea = get_base_area(height, width);

    int house_area = roofarea + basearea;

    return house_area;
}

int main(void) {

    int house1 = get_house_area(5, 10, 20);

    printf("%i \n", house1);

}