using namespace std;

int getMinEnergy(int n) {
    if (n == 0 || n == 1) return n;

    if (n % 2 == 0) return getMinEnergy(n / 2);
    return getMinEnergy(n - 1) + 1;
}

int solution(int n)
{
    return getMinEnergy(n);
}
