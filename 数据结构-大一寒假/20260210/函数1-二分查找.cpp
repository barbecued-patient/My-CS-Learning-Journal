Position BinarySearch( List L, ElementType X )
{
    Position left=1;
    Position right=L->Last;
    Position mid;
    while(left<=right){
        mid=left+(right-left)/2;
        if(X==L->Data[mid]){
            return mid;
        }else if(X>L->Data[mid]){
            left=mid+1;
        }else{
            right=mid-1;
        }
    }
    return NotFound;
}
