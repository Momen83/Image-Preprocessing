#include <iostream>
#include <cstring>
#include <cmath>
#include "bmplib.h"

using namespace std;
unsigned char image[SIZE][SIZE];
void Rotate90(unsigned char img[][SIZE])
{
    // temp grid to store on it grid after rotation
    unsigned char temp[SIZE][SIZE];
    int row=0,col=0;
  /*
   * here to rotate the image 90 degree we make every column to be row starting from last column
   * and store it in grid temp
   */
    for (int coloum = SIZE-1; coloum >=0 ; --coloum) {
        for (int roww = 0; roww <SIZE ; ++roww) {
            temp[row][col]=img[coloum][roww];
            col++;
        }
        row++;
        col=0;
    }
    // fill the img grid with the temp after rotate 90
    for (int coloum = 0; coloum <SIZE ; ++coloum) {
        for (int roww = 0; roww <SIZE ; ++roww) {
            img[coloum][roww]=temp[roww][coloum];
        }
    }

}
//_________________________________________
void loadImage (){
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
}


//_________________________________________
void saveImage (){
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
    cout<<endl<<"Successfully Saved ! \n"<<endl;

}

void rotateImg(){
    while (true)
    {
        int choice;
        cout<<"Rotate Image 90 or 180 or 270 \n ";
        cin>>choice;

        if(choice==90){
            Rotate90(image);
            break;
        }

        else if(choice==180){

            Rotate90(image);
            Rotate90(image);
            break;
        }

        else if(choice==270){
            Rotate90(image);
            Rotate90(image);
            Rotate90(image);
            break;
        }
        else{
            cout<<"Invalid angle rotation\n";
        }
    }


}
void FilterImg()
{
    // here we replace every pixel in grid with 255-pixel
    for (int coloum = 0; coloum <SIZE ; ++coloum) {
        for (int roww = 0; roww <SIZE ; ++roww) {
            image[coloum][roww]=255-image[coloum][roww];
        }
    }
}
void mergeImg()
{
    unsigned char Mergeimage[SIZE][SIZE];
   //First we store the data of array image in mergeImage array
    for (int row = 0; row < SIZE; ++row) {
        for (int coloum = 0; coloum <SIZE ; ++coloum) {
            Mergeimage[row][coloum]=image[row][coloum];
        }
    }
    //Take the second picture from the user and store it in array image
    loadImage();
    // Here we store in every pixel the average between first and second picture
    for (int row = 0; row < SIZE; ++row) {
        for (int coloum = 0; coloum <SIZE ; ++coloum) {
            image[row][coloum]=(Mergeimage[row][coloum]+image[row][coloum])/2;
        }
    }
}
void brightnessImg()
{
    int op;
    cout<<"1- Darken image with 50%\n";
    cout<<"2- Lighten image with 50%\n";
    cin>>op;
    // if first option we replace every pixel with 1/2 pixel
    // else we decrease from every pixel the (pixel+256)/2
    for (int row = 0; row <SIZE ; ++row) {
        for (int coloum = 0; coloum <SIZE ; ++coloum) {
            if(op==1)
            {
                image[row][coloum]/=2;
            }
            else{
                image[row][coloum]-=(image[row][coloum]+256)/2;
            }

        }
    }


}
int main()
{
cout<<"Hello in photoshop\n";
loadImage();
cout<<"1- rotate image\n";
cout<<"2- Filter image\n";
cout<<"3- Darken and lighten image\n";
cout<<"4- Merge image\n";
int option;cin>>option;
if(option==1)
{
    rotateImg();
}
else if(option==2)
{
 FilterImg();
}
else if(option==3)
{
    brightnessImg();
}
else if (option==4)
{
    mergeImg();
}
saveImage();
return 0;
}

