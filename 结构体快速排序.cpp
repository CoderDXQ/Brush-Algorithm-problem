int Partition(int a[],int left,int right)
{
	fuzhi(&temp,&a[left]);
	while(left<right)
	{
		while(left<right&&(panduan(&a[right],&temp)==0)) right--;////////panduan()==0
		fuzhi(&a[left],&a[right]);
		while (left<right&&(panduan(&a[left],&temp)==1)) left++;///////  panduan()==1
		fuzhi(&a[right],&a[left]);
	}
	fuzhi(&a[left],&temp);
	return left;
}

void quicksort(int a[],int left,int right)
{
	if(left<right)
	{
		int pos=Partition(a,left,right);
		quicksort(a,left,pos-1);
		quicksort(a,pos+1,right);
	}
}

int pandan(student *a,student *b)
{
	if((*a).lei<(*b).lei) return 1;
	else 
	{
	if ((*a).lei==(*b).lei)
	    {
	    	if((*a).zong>(*b).zong)	return 1;
	    	else{
	    		if((*a).zong==(*b).zong) 
				{
					if((*a).de>(*b).de)  return 1;
					else
					{
						if((*a).de==(*b).de)
						{
							if((*a).hao<(*b).hao) return 1;
							else return 0;
						}
						else return 0;
					}
				};
	    		else return 0;
			}
	    }
	else return	0;
    }
}
