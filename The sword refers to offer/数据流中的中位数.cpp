//对顶堆 max是大顶堆，min是小顶堆

template<typename T>class DynamicArray
{
public:
    void Insert(T num)
    {
        if((max.size()+min.size())&1==0)//目前一共有偶数个,往小顶堆中push_back，插入后是奇数个
        {//每次将大顶堆及新进来的数中的最大的数灌入小顶堆，保证小顶堆中所有的数都比大顶堆中的数大
            if(max.size()>0&&num<max[0])//小于大顶堆中最大的数
            {
                max.push_back(num);
                push_heap(max.begin(),max.end(),less<T>());//堆的内部处理

                num=max[0];

                pop_heap(max.begin(),max.end(),less<T>());//堆的内部处理
                max.pop_back();//弹出
            }
            min.push_back(num);
            push_heap(min.begin(),min.end(),greater<T>());//堆的内部处理
        }
        else//如果当前一共是奇数个数字，那么就网大顶堆中push_back，插入后是偶数个
        {
            if(min.size()>0 && min[0]<num)
            {//如果小顶堆中最小的数小于插进来的数num，那么num一定比大顶堆中所有的数都大，因此直接插入小顶堆
                min.push_back(num);
                push_heap(min.begin(),min.end(),greater<T>());

                num=min[0];

                pop_heap(min.begin(),min.end(),greater<T>());
                min.pop_back();//弹出
            }

            max.push_back(num);
            push_back(max.begin(),max.end(),less<T>());
        }
    }

    T GetMedian()
    {
        int size=min.size()+max.size();
        if(size==0)
            throw exception("No numbers are available");

        T median=0;
        if((size&1)==1)//总共有奇数个
            median=min[0];
        else
            median=(min[0]+max[0])/2;

        return median;
    }

private:
    vector<T> min;//小顶堆
    vector<T> max;//大顶堆
};
















































