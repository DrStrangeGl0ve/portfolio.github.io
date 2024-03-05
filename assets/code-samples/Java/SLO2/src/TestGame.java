public class TestGame {
    public static void main(String[] args) {
        Game game = new Game().setGameData();
        displayGameDetails(game);
    }

    public static void displayGameDetails(Game game) {
        System.out.println("The game between " + game.getTeam1().getSchool() + " " + game.getTeam1().getSport() + " Team " + game.getTeam1().getMascot());
        System.out.println("   and " + game.getTeam2().getSchool() + " " + game.getTeam2().getSport() + " Team " + game.getTeam2().getMascot());
        System.out.println("   takes place at " + game.getTime());
    }
}