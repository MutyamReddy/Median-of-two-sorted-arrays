double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
int x=A.size();int y=B.size();
if(x>y) return findMedianSortedArrays(B,A);
int start=0; int end=x;
while(start<=end){
    int partx=(start+end)/2; int party=(x+y+1)/2-partx;
    int minx=(partx==0)?INT_MIN:A[partx-1];
    int maxx=(partx==0)?INT_MAX:A[partx];
    int miny=(party==0)?INT_MIN:B[party-1];
    int maxy=(party==0)?INT_MAX:B[party];
    if(minx<=maxy&&miny<=maxx){
        if((x+y)%2==0){
            return ((double)(max(minx,miny)+min(maxx,maxy)))/2;
        }else{
            return max(minx,miny);
        }
    }else if(minx>maxy){
        end=partx-1;
    }else{
        start=partx+1;
    }
}
return -1;
}
