
#include "Vec3.h"

#include <iostream>
using namespace std;

int main()
{
    Vec3<int>* vecNull = nullptr;
    Vec3<int>* vecEmpty = new Vec3<int>;
    Vec3<int>* vecInt = new Vec3<int>(1, 2, 3);
    Vec3<int>* vecInt2 = new Vec3<int>(3, 2, 1);
    Vec3<float>* vecFloat = new Vec3<float>(1.5f, 2.5f, 0.5f);
    Vec3<double>* vecDouble = new Vec3<double>(1, 2, 3);
    Vec3<char>* vecChar = new Vec3<char>(1, 2, 3);

    Vec3<float>* vecCopy(vecFloat); // No consigo que llame al constructor copia. Llama al por defecto.
    //Vec3<float>* vecTrans = new Vec3<float>(vecInt); // Copy from different type?

    *vecEmpty = *vecInt + *vecInt2;     // Y si quiero poder hacerlo con esta sintaxis: v1=v2+v3 (sin ser punteros)?

    cout << endl << vecInt->x << "," << vecInt->y << "," << vecInt->z << endl;
    cout << vecInt2->x << "," << vecInt2->y << "," << vecInt2->z << endl;
    cout << "Suma:" << vecEmpty->x << "," << vecEmpty->y << "," << vecEmpty->z << endl;

    Vec3<int>* vecCross = &vecInt->CrossProduct(*vecInt2);
    cout << "Cross Product: " << vecCross->x << "," << vecCross->y << "," << vecCross->z << endl << endl;


    cout << "Normalization: " << endl << "before:" << endl;
    cout << "Original:\t" << vecFloat->x << "," << vecFloat->y << "," << vecFloat->z << endl;
    cout << "Copy:\t\t" << vecCopy->x << "," << vecCopy->y << "," << vecCopy->z << endl;
    vecCopy->Normalize();
    cout << "After:" << endl;
    cout << "Original:\t" << vecFloat->x << "," << vecFloat->y << "," << vecFloat->z << endl;
    cout << "Copy:\t\t" << vecCopy->x << "," << vecCopy->y << "," << vecCopy->z << endl << endl;

    cout << "(" << vecInt->x << "," << vecInt->y << "," << vecInt->z;
    cout << ") distance to (";
    cout << vecInt2->x << "," << vecInt2->y << "," << vecInt2->z << "): ";
    cout << vecInt->DistanceTo(*vecInt2) << endl;

    cout << "(" << vecInt->x << "," << vecInt->y << "," << vecInt->z;
    cout << ") x (";
    cout << vecInt2->x << "," << vecInt2->y << "," << vecInt2->z << "): ";
    cout << vecInt->DotProduct(*vecInt2) << endl;
    cout << "Angle between (" << vecInt->x << "," << vecInt->y << "," << vecInt->z;
    cout << ") and (";
    cout << vecInt2->x << "," << vecInt2->y << "," << vecInt2->z << "): ";
    cout << vecInt->AngleBetween(*vecInt2) << endl << endl;

    cout << "Ops with mixed types: " << endl;
    cout << vecInt->DistanceTo(*vecFloat) << endl;
    cout << vecInt->DotProduct(*vecFloat) << endl;
    cout << vecInt->AngleBetween(*vecFloat) << endl << endl; // Nan¿¿

    cout << "Other instance types: " << endl;
    cout << "Double: " << vecDouble->x << "," << vecDouble->y << "," << vecDouble->z << endl;
    cout << "Char: " << vecChar->x << "," << vecChar->y << "," << vecChar->z << endl;


}

