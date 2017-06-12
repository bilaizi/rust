package com.android.examples.githubissues.viewmodels;

import android.arch.lifecycle.LiveData;
import android.arch.lifecycle.MediatorLiveData;
import android.arch.lifecycle.ViewModel;
import android.support.annotation.NonNull;

import com.android.examples.githubissues.entities.ApiResponse;
import com.android.examples.githubissues.repositories.IssueRepository;
import com.android.examples.githubissues.repositories.IssueRepositoryImpl;

//ListIssuesViewModel will fetch the data requested by the UI from the IssueRepository.
//It has MediatorLiveData mApiResponse which is observed by the UI.
//MediatorLiveData is a subclass of MutableLiveData
//which allows us to observe one or more LiveData
//(LiveData from Repository’s getIssues() method in our case)
//and propagate the changes to it own observers (Activity in our case).

//Note:
//1.In case you want to have a ViewModel class with non-empty constructor,
//you have to create a Factory class which would create instance of you ViewModel
//and that Factory class has to implement ViewModelProvider.Factory interface.
//2.If you want reference to Application context in your View Model class,
//you can use AndroidViewModel class instead of ViewModel class.
public class ListIssuesViewModel extends ViewModel {
    private MediatorLiveData<ApiResponse> mApiResponse;
    private IssueRepository mIssueRepository;

    public ListIssuesViewModel() {
        mApiResponse = new MediatorLiveData<>();
        mIssueRepository = new IssueRepositoryImpl();
    }

    @NonNull
    public LiveData<ApiResponse> getApiResponse() {
        return mApiResponse;
    }

    public void loadIssues(@NonNull String user, String repo) {
        mApiResponse.addSource(
                mIssueRepository.getIssues(user, repo),
                apiResponse -> mApiResponse.setValue(apiResponse)
        );
    }
}