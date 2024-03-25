using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class YellowMinionManager : MonoBehaviour
{
    public GameObject yellowMinion;
    public List<GameObject> yMinionsInGame;
    public YellowUnit yellowMinionInfo;
    public int yellowMinionNum = 0;

    // Start is called before the first frame update
    void Start()
    {
        SpawnYellowMinion();
    }

    void SpawnYellowMinion()
    {
        int yellowMinionSpawnIndex = 0;
        for (int i = 0; i < yellowMinionInfo.waveSize; i++)
        {
            GameObject currentYellowMinion = Instantiate(yellowMinion, yellowMinionInfo.yellowMinionSpawnLocation[yellowMinionSpawnIndex], Quaternion.identity);
            currentYellowMinion.name = yellowMinionInfo.yellowUnitName + yellowMinionNum;
            yellowMinionSpawnIndex = (yellowMinionSpawnIndex + 1) % yellowMinionInfo.yellowMinionSpawnLocation.Length;
            yMinionsInGame.Add(currentYellowMinion);
            yellowMinionNum++;

        }

    }

    // Update is called once per frame
    void Update()
    {

    }
}
