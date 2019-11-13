# ReservationSystem
CPET - 321, Reservation System using C++


## Git Command Workflow Reminder

Following these steps while adding code to the codebase will decrease the possible overlaps in code while merging.

1) When starting to update the project always use the command:

`git pull`
- This command will fetch the updates that are in the remote repository and will add them to yor local directory. 

2) After making changes to the files and are ready to update the Github repository, use:

`git add <file-names>`
- This command "stages" the files that are ready to be committed. The staging has to be done to be able to commit and push the updates to the main repository.

3) After using the command in step 2, you will have to briefly explain what the update is in a message. 

`git commit -m <message>
- Committing is adding a message for other developers to see the updates made is this commit. It helps when developers want to go back to that state in code.

4) To send all the commits made, the command below is used.

`git push`
- Pushing the commits to the remote(main) repository creates access to all developers working on the project. 
