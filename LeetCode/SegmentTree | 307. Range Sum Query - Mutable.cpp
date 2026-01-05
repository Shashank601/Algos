class NumArray {
public:
    vector<int> seg;
    int n;
    // so size is fixed for segmenstTree array
    void build(vector<int>& nums, int idx, int l, int r) {
        if (l == r) {
            seg[idx] = nums[l];
            return;
        }
        int mid = l + (r - l)/2;
        build(nums,  2*idx + 1, l, mid);
        build(nums,  2*idx + 2, mid + 1, r);
        seg[idx] = seg[2*idx + 1] + seg[2*idx + 2];
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.assign(4 * n, 0);
        build(nums, 0, 0, n - 1); 
    }
    //<===================================================>

    void updateSeg(int idx, int& targeti, int& val, int l, int r) {
        if (l == r) {
            seg[idx] = val;
            return;
        }

        int mid = l + (r - l)/2;
        
        if (targeti <= mid) {
            updateSeg(2*idx + 1, targeti, val, l, mid);
        } else {
            updateSeg(2*idx + 2, targeti, val, mid + 1, r);
        }

        seg[idx] = seg[2*idx + 1] + seg[2*idx + 2];
    }
    
    void update(int index, int val) {
        updateSeg(0, index, val, 0, n - 1);
    }
    
    //<===================================================>

    int query(int idx, int ql, int qr, int currL, int currR) {
        if (qr < currL || currR < ql) { //out of bound
            return 0;
        }

        // if (l <= ql && qr <= r) { fk no
        //     return seg[idx];
        // }
        if (ql <= currL && currR <= qr) return seg[idx];

        else {
            int mid = currL + (currR - currL)/2;
            return query(2 * idx + 1, ql, qr, currL, mid) + query(2 * idx + 2, ql, qr, mid + 1, currR);
        }
    }

    int sumRange(int left, int right) {
        return query(0, left, right, 0, n - 1);
    }
};



lern lazy seg too and reaosn why 4*n is preffered
