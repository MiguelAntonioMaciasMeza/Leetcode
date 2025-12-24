class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    if (strs.size() == 0)
      return "";

    return divide(strs, 0, strs.size() - 1);
  }

  string divide(vector<string> &strs, int left, int right) {
    // Keep dividing until we are at the same index of left and right
    if (left == right) {
      return strs[left];
    } else {
      int midpoint = floor((left + right) / 2);
      string leftLPS = divide(strs, left, midpoint);
      string rightLPS = divide(strs, midpoint + 1, right);
      return conqueor(leftLPS, rightLPS);
    }
  }

  string conqueor(string left, string right) {
    string prefix = "";
    // Prefix size is limited by smallest string
    int maxSize =
        left.length() > right.length() ? left.length() : right.length();
    for (int i = 0; i < maxSize; i++) {
      if (left[i] == right[i]) {
        prefix = prefix + left[i];
        // We break out early if we have no match
      } else {
        break;
      }
    }

    return prefix;
  }
};