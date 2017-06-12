package com.android.examples.githubissues.repositories;

import android.arch.lifecycle.LiveData;

import com.android.examples.githubissues.entities.ApiResponse;

public interface IssueRepository {
    LiveData<ApiResponse> getIssues(String owner, String repo);
}