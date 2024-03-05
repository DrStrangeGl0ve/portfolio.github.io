

public class TestTeam {
    public static void main(String[] args) {
        Team team1 = new Team().setTeamData();
        Team team2 = new Team().setTeamData();
        Team team3 = new Team().setTeamData();

        System.out.println(team1.getSchool() + " " + team1.getSport() + " team " + team1.getMascot());
        System.out.println("   Our motto is " + Team.MOTTO);
        System.out.println(team2.getSchool() + " " + team2.getSport() + " team " + team2.getMascot());
        System.out.println("   Our motto is " + Team.MOTTO);
        System.out.println(team3.getSchool() + " " + team3.getSport() + " team " + team3.getMascot());
        System.out.println("   Our motto is " + Team.MOTTO);
    }
}
