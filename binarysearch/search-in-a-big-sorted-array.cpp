
/*******************************************************************************
 *
    Search in a Big Sorted Array

    description(lintcode
                https://www.lintcode.com/en/problem/search-in-a-big-sorted-array/
                )
    Given a big sorted array with positive integers sorted by ascending order.
    The array is so big so that you can not get the length of the whole array directly,
    and you can only access the kth number by ArrayReader.get(k) (or ArrayReader->get(k) for C++).
    Find the first index of a target number. Your algorithm should be in O(log k), where k is the first index of the target number.
    Return -1, if the number doesn't exist in the array.
    If you accessed an inaccessible index (outside of the array), ArrayReader.get will return 2,147,483,647.

    notes:
    interesting problem involved with a bit deviation from most basic binary search
    upon locating left and right in initial phase

*******************************************************************************/

/**
 * Definition of ArrayReader:
 *
 * class ArrayReader {
 * public:
 *     int get(int index) {
 *          // return the number on given index,
 *          // return -1 if index is less than zero.
 *     }
 * };
 */

class Solution {
public:
    /**
     * @param reader: An instance of ArrayReader.
     * @param target: An integer
     * @return: An integer which is the first index of target.
     */
    int searchBigSortedArray(ArrayReader *reader, int target) {

        int left = 0, right = 0;

        // first try to locate a left bound and right bound for the target
        do {
            right = (right << 1) + 1;
        } while (reader->get(right) < target);

        // then apply binary search
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            (reader->get(mid) >= target ? right : left) = mid;
        }

        // final check
        if ( reader->get(left) == target) { return left; }
        if ( reader->get(right) == target) { return right; }
        return -1;
    }
};
