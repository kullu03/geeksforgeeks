bool isDuplicatesWithinKRange(int arr,int size,int k)
{

std::map<int,int>ma;
int m=0;
for(int i = 0; i<size; i++)
{
if(k<=m)
{
if(ma.find(arr[i])== ma.end())
{
ma[arr[i]]=1;
m++;
}
else
{
ma[]

}
if(m>k)
{
ma.clear();
m=0;
}


}



}



}





}
