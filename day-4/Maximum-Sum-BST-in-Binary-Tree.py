class BSTInfo:
    def __init__(self, is_bst: bool = False,
                 max_val: Optional[int] = None,
                 min_val: Optional[int] = None,
                 total_sum: Optional[int] = None):
        self.is_bst = is_bst
        self.max_val = max_val
        self.min_val = min_val
        self.total_sum = total_sum


class Solution:
    def maxSumBST(self, root: Optional[TreeNode]) -> int:
        self.max_sum = 0

        def traverse(node: Optional[TreeNode]) -> BSTInfo:
            if not node:
                return BSTInfo(is_bst=True, max_val=-math.inf, min_val=math.inf, total_sum=0)

            left_info: BSTInfo = traverse(node.left)
            right_info: BSTInfo = traverse(node.right)

            if not left_info.is_bst or not right_info.is_bst:
                return BSTInfo()

            if node.val <= left_info.max_val or node.val >= right_info.min_val:
                return BSTInfo()

            current_sum = node.val + left_info.total_sum + right_info.total_sum
            self.max_sum = max(self.max_sum, current_sum)

            return BSTInfo(is_bst=True, max_val=max(node.val, right_info.max_val),
                           min_val=min(node.val, left_info.min_val), total_sum=current_sum)

        traverse(root)
        return self.max_sum
