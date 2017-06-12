package com.android.examples.githubissues.repositories;

import android.arch.lifecycle.LiveData;
import android.arch.lifecycle.MutableLiveData;
import android.support.annotation.NonNull;

import com.android.examples.githubissues.api.GitHubApiService;
import com.android.examples.githubissues.entities.ApiResponse;
import com.android.examples.githubissues.entities.Issue;

import java.util.List;

import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;
import retrofit2.Retrofit;
import retrofit2.converter.gson.GsonConverterFactory;

//As discussed above Repositories are used to abstract the communication
//of rest of the code to the Data sources(such as Database or API calls).
//In our case IssueRepositoryImpl will use GithubApiService to fetch data from github API
//and return the value as a LiveData.
public class IssueRepositoryImpl implements IssueRepository {
    public static final String BASE_URL = "https://api.github.com/";
    private GitHubApiService mApiService;

    public IssueRepositoryImpl() {
        Retrofit retrofit = new Retrofit.Builder()
                .addConverterFactory(GsonConverterFactory.create())
                .baseUrl(BASE_URL)
                .build();
        mApiService = retrofit.create(GitHubApiService.class);
    }

    //In the getIssues() method we create a MutableLiveData from the data obtained from retorfit.
    //MutableLiveData is the subclass of LiveData that has setValue(T) method
    //that can be used to modify the value it holds.
    public LiveData<ApiResponse> getIssues(String owner, String repo) {
        final MutableLiveData<ApiResponse> liveData = new MutableLiveData<>();
        Call<List<Issue>> call = mApiService.getIssues(owner, repo);
        call.enqueue(
                new Callback<List<Issue>>() {
                    @Override
                    public void onResponse(
                            @NonNull Call<List<Issue>> call,
                            @NonNull Response<List<Issue>> response
                    ) {
                        liveData.setValue(new ApiResponse(response.body()));
                    }

                    @Override
                    public void onFailure(
                            @NonNull Call<List<Issue>> call,
                            Throwable t
                    ) {
                        liveData.setValue(new ApiResponse(t));
                    }
                }
        );
        return liveData;
    }
}