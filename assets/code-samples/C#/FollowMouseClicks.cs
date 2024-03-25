using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FollowMouseClicks : MonoBehaviour
{

    public GameObject cursor;
    public UnityEngine.AI.NavMeshAgent agent;
    public GameObject player;
    //private Animation run;


    // Start is called before the first frame update
    void Start()
    {

        // run = GetComponent<Animation>();
        agent = GetComponent<UnityEngine.AI.NavMeshAgent>();
    }

    // Update is called once per frame
    void Update()
    {
        Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);
        RaycastHit hit;
        if (Input.GetAxis("Fire2") > 0)
        {
            if (Physics.Raycast(ray, out hit, 100))
            {
                //run.Play("HumanoidRun");
                agent.destination = hit.point;
            }
        }

    }
}
