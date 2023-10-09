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
    for (int r = SIZE - 1; r >= 0 ; --r) {
        for (int c = 0; c < SIZE ; ++c) {
            temp[row][col]=img[r][c];
            col++;
        }
        row++;
        col=0;
    }
    // fill the img grid with the temp after rotate 90
    for (int r = 0; r < SIZE ; ++r) {
        for (int c = 0; c < SIZE ; ++c) {
            img[r][c]=temp[c][r];
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
void invertImg()
{
    // here we replace every pixel in grid with 255-pixel
    for (int coloum = 0; coloum <SIZE ; ++coloum) {
        for (int roww = 0; roww <SIZE ; ++roww) {
            image[coloum][roww]=255-image[coloum][roww];
        }
    }
}
void elterImg()
{
    while (true)
    {
        int part;
        cout<<"Enter part 1 2 3 4 \n";
        cin>>part;
        if(part>4 ||part<0){
            cout<<"Invalid input try again\n";
            continue;
        }
        int row=0,col=0;
        unsigned char tempImg[SIZE/2+1][SIZE/2+1];
        if(part==1)
        {
            //row from 0 to 127 ,coloum from 0 to 127
            for (int i = 0; i <SIZE/2 ; ++i) {
                for (int j = 0; j <SIZE/2 ; ++j) {
                    tempImg[row][col]=image[i][j];
                    col++;
                }
                row++;
                col=0;
            }

        }
        else if(part==2)
        {
            //row from 0 to 127 ,coloum from 127 to 255
            for (int i = 0; i <SIZE/2 ; ++i) {
                for (int j = 127; j <SIZE ; ++j) {
                    tempImg[row][col]=image[i][j];
                    col++;
                }
                row++;
                col=0;
            }
        }
        else if(part==3)
        {
            //row from 127 to 255 ,coloum from 0 to 128
            for (int i = 127; i <SIZE ; ++i) {
                for (int j = 0; j <SIZE/2 ; ++j) {
                    tempImg[row][col]=image[i][j];
                    col++;
                }
                row++;
                col=0;
            }
        }
        else if (part==4)
        {
            //row from 127 to 255 ,coloum from 127 to 256
            for (int i = 127; i <SIZE ; ++i) {
                for (int j = 127; j <SIZE ; ++j) {
                    tempImg[row][col]=image[i][j];
                    col++;
                }
                row++;
                col=0;
            }
        }
        row=0,col=0;
        for (int i = 0; i <SIZE/2 ; ++i) {
            for (int j = 0; j <SIZE/2 ; ++j) {
                image[row][col]=  tempImg[i][j];
                image[row][col+1]=  tempImg[i][j];
                image[row+1][col]=tempImg[i][j];
                image[row+1][col+1]=tempImg[i][j];
                col+=2;
            }
            row+=2;
            col=0;
        }
        break;
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
void shrinkImg()
{
    int op;
    unsigned char ImageShrink[SIZE][SIZE];
    for (int row = 0; row <SIZE ; ++row) {
        for (int coloum = 0; coloum <SIZE ; ++coloum) {
            ImageShrink[row][coloum]=255;
        }
    }
    cout<<"1-Make dimension 1/2\n";
    cout<<"2-Make dimension 1/3\n";
    cout<<"3-Make dimension 1/4\n";
    int r=0,c=0;
   cin>>op;

   if(op==1)
   {

       for (int row = 0; row <SIZE ; row+=2) {
           for (int coloum = 0; coloum <SIZE ; coloum+=2) {
               ImageShrink[r][c]=image[row][coloum];
               c++;
           }
           c=0;
           r++;
       }

   }
   else if(op==2)
   {
       for (int row = 0; row <SIZE ; row+=3) {
           for (int coloum = 0; coloum <SIZE ; coloum+=3) {
               ImageShrink[r][c]=image[row][coloum];
               c++;
           }
           c=0;
           r++;
       }
   }
   else if(op==3)
   {
       for (int row = 0; row <SIZE ; row+=4) {
           for (int coloum = 0; coloum <SIZE ; coloum+=4) {
               ImageShrink[r][c]=image[row][coloum];
               c++;
           }
           c=0;
           r++;
       }
   }

    for (int row = 0; row <SIZE ; ++row) {
        for (int coloum = 0; coloum <SIZE ; ++coloum) {
           image[row][coloum]= ImageShrink[row][coloum];
        }
    }
}
void blurImg()
{
    for (int row = 0; row < SIZE; ++row) {
        for (int coloum = 0; coloum <SIZE; ++coloum) {
            int val=0;
            int cnt=0;
            for (int i = 0; i <3 ; ++i) {
                for (int j = 0; j <3 ; ++j) {
                    if(i+row< SIZE &&j+coloum<SIZE)
                    {
                        val+=image[i+row][j+coloum];
                        cnt++;
                    }
                }
            }
            image[row][coloum]=val/cnt;

        }
    }

}
void shuffleImg()
{
    cout<<"Enter order of 4 part do you want like 1 2 3 4, 4 3 2 1\n";
    int parts[5];
    for (int i = 1; i <=4 ; ++i) {
        cin>>parts[i];
    }
    int size=(SIZE/2+1)*(SIZE/2+1);
    int grid[5][size];
    //store first part from image from 0 to 127 row ,0 to 127 column
    int index=0;
    for (int row = 0; row <SIZE/2 ; ++row) {
        for (int column = 0; column <SIZE/2 ; ++column) {
            grid[1][index]=image[row][column];
            index++;
        }
    }
    index=0;
    //store second part from image from 0 to 127 row ,127 to 255 column
    for (int row = 0; row <SIZE/2 ; ++row) {
        for (int column = SIZE/2; column <SIZE; ++column) {
            grid[2][index]=image[row][column];
            index++;
        }
    }
    index=0;
    //store third part from image from 127 to 256 row ,0 to 127 column
    for (int row = SIZE/2; row <SIZE ; ++row) {
        for (int column =0; column <SIZE/2; ++column) {
            grid[3][index]=image[row][column];
            index++;
        }
    }
    index=0;
    //store four part from image from 127 to 256 row ,127 to 256 column
    for (int row = SIZE/2; row <SIZE ; ++row) {
        for (int column =SIZE/2; column <SIZE; ++column) {
            grid[4][index]=image[row][column];
            index++;
        }
    }
    //store of first part of image the part which user want
    index=0;
    for (int row = 0; row <SIZE/2 ; ++row) {
        for (int column = 0; column <SIZE/2 ; ++column) {
            image[row][column]=grid[parts[1]][index];
            index++;
        }
    }
    //store of second part of image the part which user want
    index=0;
    for (int row = 0; row <SIZE/2 ; ++row) {
        for (int column = SIZE/2; column <SIZE; ++column){
            image[row][column]=grid[parts[2]][index];
            index++;
        }
    }
    //store of third part of image the part which user want
    index=0;
    for (int row = SIZE/2; row <SIZE ; ++row) {
        for (int column =0; column <SIZE/2; ++column) {
            image[row][column]=grid[parts[3]][index];
            index++;
        }
    }
    //store of fourth part of image the part which user want
    index=0;
    for (int row = SIZE/2; row <SIZE ; ++row) {
        for (int column =SIZE/2; column <SIZE; ++column) {
            image[row][column]=grid[parts[4]][index];
            index++;
        }
    }
}
void blackWhiteImg()
{
    int averageImg=0;
    for (int r = 0; r <SIZE ; ++r) {
        for (int c = 0;c < SIZE; ++c) {
            averageImg+=image[r][c];
        }
    }
    averageImg/=(SIZE*SIZE);
    for (int r = 0; r <SIZE ; ++r) {
        for (int c = 0;c < SIZE; ++c) {
           if(image[r][c]>averageImg) {
               image[r][c] = 255;
           }
           else
           {
               image[r][c] = 0;
           }
        }
    }
}
void FlipImg()
{
    unsigned char temp[SIZE][SIZE];
    int r=0,c=0;
    for (int row = SIZE-1; row >=0 ; --row) {
        for (int col =0; col <SIZE ; ++col) {
            temp[r][c]=image[row][col];
            c++;
        }
        r++;
        c=0;
    }
    for (int row = 0; row <SIZE ; ++row) {
        for (int coloum = 0; coloum <SIZE ; ++coloum) {
            image[row][coloum]= temp[row][coloum];
        }
    }
}
void DetectImageEdges()
{
    int averageImg=0;
    for (int r = 0; r <SIZE ; ++r) {
        for (int c = 0;c < SIZE; ++c) {
          if(image[r][c]>80)
          {
              image[r][c]=0;
          }
          else
          {
              image[r][c]=255;
          }
        }
    }
}
int main()
{
cout<<"Hello in photoshop\n";
loadImage();
cout<<"1- rotate image\n";
cout<<"2- invert image\n";
cout<<"3- Enlarge Image\n";
cout<<"4- Darken and lighten image\n";
cout<<"5- Merge image\n";
cout<<"6- Shrink Image\n";
cout<<"7- Blur Image\n";
cout<<"8- Shuffle Image\n";
cout<<"9- black-white Image\n";
cout<<"10- Flip image\n";
cout<<"11- Detect Image Edges\n";
int option;cin>>option;
if(option==1)
{
    rotateImg();
}
else if(option==2)
{
    invertImg();
}
else if(option==3)
{
    elterImg();
}
else if(option==4)
{
    brightnessImg();
}
else if(option==5)
{
    mergeImg();
}
else if(option==6)
{
 shrinkImg();
}
else if(option==7)
{
blurImg();
}
else if(option==8)
{
   shuffleImg();
}
else if(option==9)
{
    blackWhiteImg();
}
else if(option==10)
{
    FlipImg();
}
else if(option==11)
{
    DetectImageEdges();
}
saveImage();
return 0;
}

