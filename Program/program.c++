#include <iostream>
#include <cmath>
using namespace std;
void exactSolution();
void JacobiMethod();
void SeidelMethod();
void BisectionMethod();
void SimpleIterationMethod();
int main()
{
    int n=0;
    her:
    cout<<"1- To liner equation"<<endl;
    cout<<"2- To nonLiner equation"<<endl;
    cout<<"3- To Exit"<<endl;
    cout<<"Enter the number you choose : ";
    cin>>n;
    cout<<"\n--------------------------------------------------------\n";
    switch (n)
    {
    case 1:
    {
        int num;
        here:
        cout<<"1- To exact solution"<<endl;
        cout<<"2- To numerical solution"<<endl;
        cout<<"3- To back to home page"<<endl;
        cout<<"Enter the number you choose : ";
        cin>>num;
        switch(num)
        {
            case 1:
                cout<<"\n--------------------------------------------------------\n";
                exactSolution();
                break;
            case 2:
            {    int number;
                in:
                cout<<"\n--------------------------------------------------------\n";
                cout<<"1- To Jacobi method"<<endl;
                cout<<"2- To Seidel method"<<endl;
                cout<<"3- To back to home page"<<endl;
                cout<<"Enter the number you choose : ";
                cin>>number;
                switch(number)
                {
                    case 1:
                        cout<<"\n--------------------------------------------------------\n";
                        JacobiMethod();
                        break;
                    case 2:
                         cout<<"\n--------------------------------------------------------\n";
                        SeidelMethod();
                        break;
                    case 3:
                        cout<<"\n--------------------------------------------------------\n";
                        goto her;
                        break;
                    default:
                        cout<<"Error! --> chose a valid number";
                        goto in;
                }
                break;
            }
            case 3:
                cout<<"\n--------------------------------------------------------\n";
                goto her;
                break;
            default:
                cout<<"Error! --> chose avalid number"<<endl;
                goto here;
 
        }
        
        break;
    }

    case 2:
    {
        int num;
        on:
        cout<<"\n--------------------------------------------------------\n";
        cout<<"1- To Bisection method"<<endl;
        cout<<"2- To SimpleIteration method"<<endl;
        cout<<"3- To back to home page"<<endl;
        cout<<"Enter the number you choose : ";
        cin>>num;
        switch(num)
        {
            case 1:
                cout<<"\n--------------------------------------------------------\n";
                BisectionMethod();
                break;
            case 2:
                cout<<"\n--------------------------------------------------------\n";
                SimpleIterationMethod();
                break;
            case 3:
                cout<<"\n--------------------------------------------------------\n";
                goto her;
                break;
            default:
                cout<<"Error! --> chose avalid number"<<endl;
                goto on;
        }
        break;
    }

    case 3:
        break;

    default:
        cout<<"Error! --> Enter avalid number"<<endl;
        goto her;
        break;
    }
}

//! بتحط قيم المصفوفه
void setMatrix(double Matrix[3][4])
{
    cout << "Enter x1 values: " << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "num " << i + 1 << ": ";
        cin >> Matrix[i][0];
    }
    cout << "\n-------------------------------------------\n";
    cout << "Enter x2 values: " << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "num " << i + 1 << ": ";
        cin >> Matrix[i][1];
    }
    cout << "\n-------------------------------------------\n";
    cout << "Enter x3 values: " << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "num " << i + 1 << ": ";
        cin >> Matrix[i][2];
    }
    cout << "\n-------------------------------------------\n";
    cout << "Enter result values: " << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "num " << i + 1 << ": ";
        cin >> Matrix[i][3];
    }
}
//! بتعدل المصفوفه بحيث يبقي فيها 3 اصفار
void operationsMatrix(double Matrix[3][4])
{
    //! بتصفر اول قيمه في الصف الثاني
    //! factor1   (هو المعامل اللي بيجعل اول قيمه في الصف التاني = اول قيمه في الصف الاول (علشان ناتج الطرح يبقي صفر
    double factor1 = (Matrix[1][0] / Matrix[0][0]);
    for (int i = 0; i < 4; i++)
    {
        Matrix[1][i] -= (factor1 * Matrix[0][i]);
    }
    //! بتصفر اول قيمه في الصف الثالث
    //! factor2   (هو المعامل اللي بيجعل اول قيمه في الصف الثالث = اول قيمه في الصف الاول (علشان ناتج الطرح يبقي صفر
    double factor2 = (Matrix[2][0] / Matrix[0][0]);
    for (int i = 0; i < 4; i++)
    {
        Matrix[2][i] -= (factor2 * Matrix[0][i]);
    }
    //! بتصفر تاني قيمه في الصف الثالث
    //! factor3   (هو المعامل اللي بيجعل تاني قيمه في الصف الثالث = تاني قيمه في الصف تاني (علشان ناتج الطرح يبقي صفر
    double factor3 = (Matrix[2][1] / Matrix[1][1]);
    for (int i = 0; i < 4; i++)
    {
        Matrix[2][i] -= (factor3 * Matrix[1][i]);
    }
}
//! to print values of x1,x2,x3
void print(double x1, double x2, double x3)

{
    cout << "\n___________________________________________\n";
    cout << "___________________________________________\n\n";
    cout << "x1 = " << x1 << endl;
    cout << "x2 = " << x2 << endl;
    cout << "x3 = " << x3 << endl;
}
//! GaussEliminationMethod
void exactSolution()
{
    double Matrix[3][4];
    setMatrix(Matrix);
    operationsMatrix(Matrix);
    double x1 = 0, x2 = 0, x3 = 0;
    //! x بعوض علطول في المصفوفه كل صف بيطلع
    x3 = Matrix[2][3] / Matrix[2][2];
    x2 = (Matrix[1][3] - (Matrix[1][2] * x3)) / Matrix[1][1];
    x1 = (Matrix[0][3] - (Matrix[0][2] * x3) - (Matrix[0][1] * x2)) / Matrix[0][0];
    print(x1, x2, x3);
}

void JacobiMethod()
{

    double a1, a2, a3;
    cout << "Enter parameters of x1 :" << endl;
    cout << "Enter parameter a1 :";
    cin >> a1;

    cout << "Enter parameter a2 :";
    cin >> a2;

    cout << "Enter parameter a3:";
    cin >> a3;

    cout << "\n-------------------------------------------\n";
    double b1, b2, b3;
    cout << "Enter parameters of x2 :" << endl;
    cout << "Enter parameter b1 :";
    cin >> b1;

    cout << "Enter parameter b2 :";
    cin >> b2;

    cout << "Enter parameter b3:";
    cin >> b3;

    cout << "\n-------------------------------------------\n";
    double c1, c2, c3;
    cout << "Enter parameters of x3 :" << endl;
    cout << "Enter parameter c1 :";
    cin >> c1;

    cout << "Enter parameter c2 :";
    cin >> c2;

    cout << "Enter parameter c3:";
    cin >> c3;

    cout << "\n-------------------------------------------\n";
    double r1, r2, r3;
    cout << "Enter the result of equations :" << endl;
    cout << "Enter parameter r1 :";
    cin >> r1;

    cout << "Enter parameter r2 :";
    cin >> r2;

    cout << "Enter parameter r3:";
    cin >> r3;


    double x1 = 0, x2 = 0, x3 = 0;

    double x1_1 = (r1 - (b1 * x2) - (c1 * x3)) / a1;
    double x2_1 = (r2 - (a2 * x1) - (c2 * x3)) / b2;
    double x3_1 = (r3 - (a3 * x1) - (b3 * x2)) / c3;

    double x1_2 = (r1 - (b1 * x2_1) - (c1 * x3_1)) / a1;
    double x2_2 = (r2 - (a2 * x1_1) - (c2 * x3_1)) / b2;
    double x3_2 = (r3 - (a3 * x1_1) - (b3 * x2_1)) / c3;

    double x1_3 = (r1 - (b1 * x2_2) - (c1 * x3_2)) / a1;
    double x2_3 = (r2 - (a2 * x1_2) - (c2 * x3_2)) / b2;
    double x3_3 = (r3 - (a3 * x1_2) - (b3 * x2_2)) / c3;

    double x1_4 = (r1 - (b1 * x2_3) - (c1 * x3_3)) / a1;
    double x2_4 = (r2 - (a2 * x1_3) - (c2 * x3_3)) / b2;
    double x3_4 = (r3 - (a3 * x1_3) - (b3 * x2_3)) / c3;

    cout << "\n___________________________________________\n";
    cout << "___________________________________________\n\n";
    cout<<"x1 = "<<x1_4<<endl;
    cout<<"x2 = "<<x2_4<<endl;
    cout<<"x3 = "<<x3_4<<endl;

}

void SeidelMethod()
{

    double a1, a2, a3;
    cout << "Enter parameters of x1 :" << endl;
    cout << "Enter parameter a1 : ";
    cin >> a1;

    cout << "Enter parameter a2 : ";
    cin >> a2;

    cout << "Enter parameter a3 : ";
    cin >> a3;

    cout << "\n-------------------------------------------\n";
    double b1, b2, b3;
    cout << "Enter parameters of x2 :" << endl;
    cout << "Enter parameter b1 : ";
    cin >> b1;

    cout << "Enter parameter b2 : ";
    cin >> b2;

    cout << "Enter parameter b3 : ";
    cin >> b3;

    cout << "\n-------------------------------------------\n";
    double c1, c2, c3;
    cout << "Enter parameters of x3 :" << endl;
    cout << "Enter parameter c1 : ";
    cin >> c1;

    cout << "Enter parameter c2 : ";
    cin >> c2;

    cout << "Enter parameter c3 : ";
    cin >> c3;

    cout << "\n-------------------------------------------\n";
    double r1, r2, r3;
    cout << "Enter the result of equations :" << endl;
    cout << "Enter parameter r1 : ";
    cin >> r1;

    cout << "Enter parameter r2 : ";
    cin >> r2;

    cout << "Enter parameter r3 : ";
    cin >> r3;


    double x1 = 0, x2 = 0, x3 = 0;

    for(int i=0; i<4;i++)
    {
        x1 = (r1 - (b1 * x2) - (c1 * x3)) / a1;
        x2 = (r2 - (a2 * x1) - (c2 * x3)) / b2;
        x3 = (r3 - (a3 * x1) - (b3 * x2)) / c3;
    }


    cout << "\n___________________________________________\n";
    cout << "___________________________________________\n\n";
    cout<<"x1 = "<<x1<<endl;
    cout<<"x2 = "<<x2<<endl;
    cout<<"x3 = "<<x3<<endl;

}

void BisectionMethod()
{
    double x;
    double f_x = pow(x, 6) - x - 1;
    double a, b;
    cout << "Enter the interval point :"<<endl;
    cout << "Enter a : ";
    cin >> a;
    cout << "Enter b : ";
    cin >> b;
    double f_a = pow(a, 6) - a - 1;
    double f_b = pow(b, 6) - b - 1;

    for (int i = 0; i < 3; i++)
    {
        double c = (a + b) / 2;
        cout<<c;
        double f_c = pow(c, 6) - c - 1;
        if ((f_c > 0 && f_a > 0)||(f_c < 0 && f_a < 0))
        {
            a=c;
        }

        if ((f_c > 0 && f_b > 0)||(f_c < 0 && f_b < 0))
        {
            b=c;
        }
    }
    cout<<"___________________________________________________"<<endl;
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
}

void SimpleIterationMethod()
{
    double x, x0;
    double f_x = pow(x, 3) - (2 * x) - 5;
    cout << "Enter the initial point x0 : ";
    cin >> x0;
    x = (pow(x, 3) - 5) / 2;
    double xPar = (1.5) * pow(x, 2);
    double xPar_x0 = (1.5) * pow(x0, 2);

    if (xPar_x0 < 1)
    {
        for (int i = 0; i < 7; i++)
        {
            x = (pow(x0, 3) - 5) / 2;
            x0 = x;
        }
    }
    else
    {
        x = pow(((2 * x) + 5), (0.333333333));
        xPar = (0.666666667) * pow(((2 * x) + 5), (-0.666666667));
        xPar_x0 = (0.666666667) * pow(((2 * x0) + 5), (-0.666666667));
        if (xPar_x0 < 1)
        {
            for (int i = 0; i < 3; i++)
            {
                x =  pow(((2 * x0) + 5), (0.333333333));
                x0 = x;
            }            
        }
    }
    cout<<"___________________________________________________"<<endl;
    cout<<"x = "<<x;
}