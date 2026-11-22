
void hoanvi(int& a, int b);
void hoanvi(int& a, int b){
    int t = a;
    a = b;
    b = a;
}

void main(){
    int a = 5;
    a = 100;
    {
        int a = 5;
        a = 10;
    }
    a = 20;
    int b = 10;

    hoanvi(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << a << endl;
}