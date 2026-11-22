#include<bits/stdc++.h>
using namespace std;

int main(){
    float start, end, total_amount=0.0;
    cin>>start>>end;
    float total_amount = 0.0;
    // TODO
    float hours_k1 = 0.0;
    float hours_k2 = 0.0;
    float hours_k3 = 0.0;

    float s = start;
    float e = end;
    if (s == e) {
        s = 0.0;
        e = 24.0;
    }

    if (s < e) {
        float os1 = s;
        if (os1 < 0.0) {
            os1 = 0.0;
        }
        float oe1 = e;
        if (oe1 > 7.0) {
            oe1 = 7.0;
        }
        if (os1 < oe1) {
            hours_k1 += (oe1 - os1);
        }

        float os2 = s;
        if (os2 < 7.0) {
            os2 = 7.0;
        }
        float oe2 = e;
        if (oe2 > 17.0) {
            oe2 = 17.0;
        }
        if (os2 < oe2) {
            hours_k2 += (oe2 - os2);
        }

        float os3 = s;
        if (os3 < 17.0) {
            os3 = 17.0;
        }
        float oe3 = e;
        if (oe3 > 24.0) {
            oe3 = 24.0;
        }
        if (os3 < oe3) {
            hours_k3 += (oe3 - os3);
        }
    } else {
        float os1 = s;
        if (os1 < 0.0) {
            os1 = 0.0;
        }
        float oe1 = 24.0;
        if (oe1 > 7.0) {
            oe1 = 7.0;
        }
        if (os1 < oe1) {
            hours_k1 += (oe1 - os1);
        }

        float os2 = s;
        if (os2 < 7.0) {
            os2 = 7.0;
        }
        float oe2 = 24.0;
        if (oe2 > 17.0) {
            oe2 = 17.0;
        }
        if (os2 < oe2) {
            hours_k2 += (oe2 - os2);
        }

        float os3 = s;
        if (os3 < 17.0) {
            os3 = 17.0;
        }
        float oe3 = 24.0;
        if (oe3 > 24.0) {
            oe3 = 24.0;
        }
        if (os3 < oe3) {
            hours_k3 += (oe3 - os3);
        }

        float os1_b = 0.0;
        if (os1_b < 0.0) {
            os1_b = 0.0;
        }
        float oe1_b = e;
        if (oe1_b > 7.0) {
            oe1_b = 7.0;
        }
        if (os1_b < oe1_b) {
            hours_k1 += (oe1_b - os1_b);
        }

        float os2_b = 0.0;
        if (os2_b < 7.0) {
            os2_b = 7.0;
        }
        float oe2_b = e;
        if (oe2_b > 17.0) {
            oe2_b = 17.0;
        }
        if (os2_b < oe2_b) {
            hours_k2 += (oe2_b - os2_b);
        }

        float os3_b = 0.0;
        if (os3_b < 17.0) {
            os3_b = 17.0;
        }
        float oe3_b = e;
        if (oe3_b > 24.0) {
            oe3_b = 24.0;
        }
        if (os3_b < oe3_b) {
            hours_k3 += (oe3_b - os3_b);
        }
    }

    float m1 = hours_k1 * 60.0;
    float m2 = hours_k2 * 60.0;
    float m3 = hours_k3 * 60.0;

    float c1 = m1 * 300.0;
    if (m1 > 240.0) {
        c1 *= 0.85;
    }

    float c2 = m2 * 400.0;
    if (m2 > 360.0) {
        c2 *= 0.90;
    }

    float c3 = m3 * 350.0;
    if (m3 > 240.0) {
        c3 *= 0.88;
    }

    total_amount = c1 + c2 + c3;
    // END TODO
    cout<<round(total_amount);
    return round(total_amount);
}