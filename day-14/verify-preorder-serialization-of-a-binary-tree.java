class Solution {
    public boolean isValidSerialization(String preorder) {
        String[] nodes = preorder.split(",");
        int bf = 1;

        for(String node: nodes) {
            bf--;

            if(bf < 0) {
                return false;
            }
            
            if(!node.equals("#")) {
                bf += 2;
            }
        }

        return bf == 0;
    }
}