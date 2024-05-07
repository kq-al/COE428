void mySort(int d[], unsigned int n)
{
int a, b; 

for (int i=1; i<n; i++){
a = i-1;
b = d[i];

while(a>=0 && d[a]>b){
d[b+1]=d[b];
b--;
}

d[a+1]=b;
}
