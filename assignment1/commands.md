1.Create and Checkout a New Branch

To add some functions to repository you need to create new branch, and which can be created by using following command:

git checkout -b branchName

above command will create new branch named branchName

2.Configure user name

So as to specify which user has made change/commit, it is necessary to configure name/email of a user.and this can be done by using following commands. 

git config --global user.name "Siddhant"
git config --global user.email siddhant@example.com


3.Add files

If you would like to add new files to current branch then you can add it by using following command:

git add filename

And so as to add all files from current directory use following command.

git add .

4.Commit

after making changes in the files it is necessary to commit those changes.commiting various changes helps us to restore changes.and it is necessary to add messege at every commit so to detect, for which change you are commiting.

To commit following command is used:

git commit -m "Commit message"

5.Push

When you make changes in files,these changes are made locally.you must push these changes to remote repository.

for example if you want to Send changes to the master branch of your remote repository you can use following command

git push origin master

6.Status


If you want to see which files are yet to be commit or add but have already modified or created,you can see by status command

this command will list the files you've changed and those you still need to add or commit:

git status

7.branch
 
To list all the branches in your repo, and also to tell you what branch you're currently in you can use following command:

git branch

8.Merge 

If you have created new branch and if you would like to merge it into any previous branch then you have to go to that branch first where you would like to merge.
and then you can run following command to merge branch say testing into staging

git merge testing 




