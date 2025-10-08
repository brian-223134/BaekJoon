#include <bits/stdc++.h>
using namespace std;

using qd = __float128;

static constexpr qd PI = 3.14159265358979323846264338327950288419716939937510Q;
static constexpr qd TWO_PI = 6.28318530717958647692528676655900576839433879875021Q;

static inline qd qabs(qd x) { return x < 0 ? -x : x; }

static void print_int128(__int128 v)
{
    if (v == 0)
    {
        cout << '0';
        return;
    }
    if (v < 0)
    {
        cout << '-';
        v = -v;
    }
    char buf[64];
    int idx = 0;
    while (v > 0)
    {
        int d = (int)(v % 10);
        buf[idx++] = '0' + d;
        v /= 10;
    }
    while (idx--)
        cout << buf[idx];
}

// 소수 6자리 고정 출력: __float128 -> 정수 스케일에서 반올림 후 출력
static void print_qd_fixed6(qd x)
{
    const __int128 SCALE = 1000000;
    qd r = x * (qd)SCALE;
    __int128 k = (__int128)(r + (r >= 0 ? 0.5Q : -0.5Q));
    __int128 ip = k / SCALE;
    __int128 fp = k % SCALE;
    if (fp < 0)
        fp = -fp;

    print_int128(ip);
    cout << '.';
    // 소수부 6자리 0패딩
    __int128 p = 100000;
    while (p > 0)
    {
        __int128 d = fp / p;
        cout << (char)('0' + (int)d);
        fp %= p;
        p /= 10;
    }
}

static inline qd reduce_2pi(qd x)
{
    long double ratio_ld = (long double)(x / TWO_PI);
    long long k = llroundl(ratio_ld);
    x -= (qd)k * TWO_PI;
    if (x > PI)
        x -= TWO_PI;
    else if (x < -PI)
        x += TWO_PI;
    return x;
}

// 호너형 누적 합으로 사인값 계산
static qd sin_q(qd x)
{
    x = reduce_2pi(x);
    if (x > PI / 2)
        x = PI - x;
    if (x < -PI / 2)
        x = -PI - x; // 대칭 사용

    qd x2 = x * x;
    // sin(x) = x - x^3/3! + x^5/5! - ...
    qd term = x; // 현재 항
    qd sum = x;  // 누적합

    // i = 3,5,7,..., 최대 35차 정도면 __float128에서 충분히 수렴
    for (int i = 3, s = -1; i <= 35; i += 2, s = -s)
    {
        term *= x2 / ((qd)(i - 1) * (qd)i);
        sum += (s > 0 ? term : -term);
        if (qabs(term) < 1e-34Q)
            break; // 조기 종료
    }
    return sum;
}

static qd A, B, C;
static inline qd f(qd x) { return A * x + B * sin_q(x) - C; }

static qd solve_root()
{
    // sin이 [-1,1]에 포함된다는 것을 이용
    qd lo = (C - B) / A;
    qd hi = (C + B) / A;
    qd flo = f(lo), fhi = f(hi);

    // 같은 부호면 확장 (100~200 정도면 충분할듯?)
    if (flo * fhi > 0)
    {
        for (int k = 0; k < 200 && flo * fhi > 0; ++k)
        {
            lo -= 1;
            flo = f(lo);
            hi += 1;
            fhi = f(hi);
        }
    }

    // 이분법 반복
    for (int it = 0; it < 400; ++it)
    {
        qd mid = (lo + hi) * 0.5Q;
        qd fmid = f(mid);
        if (qabs(fmid) < 1e-28Q)
            return mid;
        if (flo * fmid <= 0)
        {
            hi = mid;
            fhi = fmid;
        }
        else
        {
            lo = mid;
            flo = fmid;
        }
    }
    return (lo + hi) * 0.5Q;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a_in, b_in, c_in;
    if (!(cin >> a_in >> b_in >> c_in))
        return 0;

    A = (qd)a_in;
    B = (qd)b_in;
    C = (qd)c_in;

    // 해 구하기
    qd root = solve_root();

    // __float128을 그대로 6자리 반올림 출력
    print_qd_fixed6(root);
    cout << '\n';
    return 0;
}
