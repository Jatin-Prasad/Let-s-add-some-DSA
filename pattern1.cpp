public class ForestVisualizer {

    static void nForest(int n) {
        if (n <= 0) {
            System.out.println("n should be a positive integer.");
            return;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print("* ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        // Example usage:
        int N = 3;
        nForest(N);
    }
}
