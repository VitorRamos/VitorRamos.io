#include <iostream>
#include <cv.h>
#include <highgui.h>
#include <time.h>
#include <stdlib.h>

using namespace cv;
using namespace std;

int main(int, char**)
{
    srand(time(NULL));
    Mat image;
    Vec3b val;
    int n; // raiz do numero de regioes

    image= imread("abc.jpg",CV_LOAD_IMAGE_COLOR);
    if(!image.data)
        cout << "nao abriu abc.jpg" << endl;

    namedWindow("janela",WINDOW_AUTOSIZE);

    cout << "Digite o Numero de Regioes : ";
    cin >> n; // numero de divisoes em uma linha
    int wr= image.size().width/n, hr= image.size().height/n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            // A ideia e pegar cada regiao e trocar com uma regiao aleatoria na imagem
            int rx= rand()%n, ry= rand()%n; // duas posicoes aleatorias de regioes
            Mat randpos= image(Rect(wr*rx,hr*ry,wr,hr)); // a regiao escolhida aleatoriamente
            Mat aux= image(Rect(wr*i,hr*j,wr, hr)).clone(); // a regiao atual
            randpos.copyTo(image(Rect(wr*i,hr*j,wr, hr))); // copia a regiao aleatoria na regiao atual
            aux.copyTo(image(Rect(wr*rx,hr*ry,wr,hr))); // copia a regial atual na regiao aleatoria
        }
    }
    imshow("janela", image);
    imwrite("abc2.jpg", image);
    waitKey();
    return 0;
}
